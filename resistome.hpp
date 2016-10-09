#ifndef RESISTOME_HPP
#define RESISTOME_HPP

#include "record.hpp"
#include "alignment.hpp"
#include "annotation_reader.hpp"

#include <map>
#include <vector>
#include <string>

class resistome {
public:
	resistome();
	void process_gene_level(std::map<std::string, record> &records, const std::vector<alignment> &alignments);
	void process_resistome(std::map<std::string, record> &records, const std::map<std::string, annotation_fields> &annot);
	void write_resistome(const std::string &sample_name, std::map<std::string, record> &records);
	void write_gene_level(const std::string &sample_name, std::map<std::string, record> &records);
	void write_class_level(const std::string &sample_name);
	void write_mechanism_level(const std::string &sample_name);
	void write_group_level(const std::string &sample_name);
private:
	std::map<std::string, int> class_level;
	std::map<std::string, int> mechanism_level;
	std::map<std::string, int> group_level;
};

#endif // RESISTOME_HPP
