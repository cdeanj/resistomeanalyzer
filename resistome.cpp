#include <iostream>
#include <fstream>
#include "resistome.hpp"

resistome::resistome() {}

void resistome::process_gene_level(std::map<std::string, record> &records, const std::vector<struct alignment> &alignments) {
	for(int i = 0; i < alignments.size(); i++) {
		std::string rname = alignments[i].rname;
		auto rec = records.find(rname);
		if(rec == records.end()) continue;

		rec->second.update_gene_hits();

        	int pos_in_read = 0;
        	int pos_in_gene = alignments[i].pos-1;

        	int gene_length = rec->second.get_gene().length();

        	for(int j = 0; j < alignments[i].cigar.size(); j++) {
                	int occurrence = alignments[i].cigar[j].first;
                	char operation = alignments[i].cigar[j].second;
                	int start = pos_in_gene;
                	int stop = start + occurrence;
			if(stop > gene_length) {
                        	stop = gene_length;
                	}

                	switch(operation) {
                        	case 'M':
                                	for(int k = start; k < stop; k++) {
                                        	rec->second._base_hits[k] = 1;
                                        	pos_in_gene++;
                                        	pos_in_read++;
                                	}
                                	break;
                        	case '=':
                                	for(int k = start; k < stop; k++) {
                                        	rec->second._base_hits[k] = 1;
                                        	pos_in_gene++;
                                        	pos_in_read++;
                                	}
                                	break;
                        	case 'D':
                                	pos_in_gene += occurrence;
                                	break;
                        	case 'N':
                                	pos_in_gene += occurrence;
                                	break;
                        	case 'S':
                                	pos_in_read += occurrence;
                                	break;
                        	case 'I':
                                	pos_in_read += occurrence;
                                	pos_in_gene += occurrence;
                                	break;
                        	case 'H':
                                	break;
                        	case 'P':
                                	pos_in_gene += occurrence;
                                	pos_in_read += occurrence;
                                	break;
                        	case 'X':
                                	pos_in_gene += occurrence;
                                	pos_in_read += occurrence;
                                	break;
                        	default:
                                	break;
                	}
        	}
	}
}

void resistome::process_resistome(std::map<std::string, record> &records, const std::map<std::string, annotation_fields> &annot) {
	for(auto rec = records.begin(); rec != records.end(); ++rec) {
		std::string reference_name = rec->first;
		for(auto header = annot.begin(); header != annot.end(); ++header) {
			if(header->first == reference_name) {
				if(rec->second._gene_hits > 0) {
					class_level[header->second._class_l] += rec->second._gene_hits;
					mechanism_level[header->second._mechanism_l] += rec->second._gene_hits;
					group_level[header->second._group_l] += rec->second._gene_hits;
				}
				break;
			}
		}		
	}
}

void resistome::write_gene_level(const std::string &gene_fp, const std::string &sample_name, std::map<std::string, record> &records) {
	std::ofstream ofs(gene_fp + ".tsv");
	ofs << "Sample\t" << "Gene\t" << "Hits\t" << "Gene Fraction\n";
	for(auto it = records.begin(); it != records.end(); ++it) {
		ofs << sample_name << "\t" << it->first << "\t" << it->second._gene_hits << "\t" << it->second.coverage() << std::endl;
	}
}

void resistome::write_class_level(const std::string &class_fp, const std::string &sample_name) {
	std::ofstream ofs(class_fp + ".tsv");
	ofs << "Sample\t" << "Class\t" << "Hits\n";
	for(auto it = class_level.begin(); it != class_level.end(); ++it) {
		ofs << sample_name << "\t" << it->first << "\t" << it->second << std::endl;
	}
}

void resistome::write_mechanism_level(const std::string &mech_fp, const std::string &sample_name) {
	std::ofstream ofs(mech_fp + ".tsv");
	ofs << "Sample\t" << "Mechanism\t" << "Hits\n";
        for(auto it = mechanism_level.begin(); it != mechanism_level.end(); ++it) {
                ofs << sample_name << "\t" << it->first << "\t" << it->second << std::endl;
        }
}

void resistome::write_group_level(const std::string &group_fp, const std::string &sample_name) {
	std::ofstream ofs(group_fp + ".tsv");
	ofs << "Sample\t" << "Group\t" << "Hits\n";
        for(auto it = group_level.begin(); it != group_level.end(); ++it) {
                ofs << sample_name << "\t" << it->first << "\t" << it->second << std::endl;
        }
}

void resistome::write_resistome(cmd_args args, const std::string &sample_name, std::map<std::string, record> &records) {
	write_gene_level(args.gene_fp, sample_name, records);
	write_class_level(args.class_fp, sample_name);
	write_mechanism_level(args.mech_fp, sample_name);
	write_group_level(args.group_fp, sample_name);
}
