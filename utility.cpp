#include "utility.hpp"
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>

namespace utility {
	bool is_valid_alignment(std::string &alignment) {
		std::string field;
		std::istringstream ss(alignment);
		std::vector<std::string> parts;
		while(ss >> field) {
			parts.push_back(field);
		}

		if(!(is_good_rname(parts[2])))
			return false;
		if(!(is_good_cigar(parts[5]))) 
			return false;
		if(!(is_good_seq(parts[9])))
			return false;
		if(!(is_good_flag(atoi(parts[1].c_str()))))
			return false;
		if(!(is_good_pos(atoi(parts[3].c_str()))))
			return false;
		
		return true;
	}

	bool is_good_rname(const std::string &rname) {
		return rname.compare("*") != 0;
	}

	bool is_good_cigar(const std::string &cigar) {
		return cigar.compare("*") != 0;
	}

	bool is_good_seq(const std::string &seq) {
		return seq.compare("*") != 0;
	}

	bool is_good_flag(const int flag) {
		return (flag & 4) == 0;
	}
	
	bool is_good_pos(const int pos) {
		return pos != 0;
	}

	int rando(const int i) {
        	return rand() % i;
	}

	void init_alignment(struct alignment *a, const std::string &al) {
		std::string field;
		std::istringstream ss(al);
		std::vector<std::string> parts;
		while(ss >> field) {
			parts.push_back(field);
		}
		a->flag = atoi(parts[1].c_str());
		a->pos = atoi(parts[3].c_str());
		a->rname = parts[2];
		a->cigar = get_cigar_ops(parts[5]);
		a->seq = parts[9];
	}

	std::vector<std::pair<int,char> > get_cigar_ops(const std::string &cigar) {
		int count;
		char operation;
		std::vector<std::pair<int,char> > vp;
		std::istringstream ss(cigar);
		while(ss >> count >> operation) {
			vp.push_back(std::make_pair(count,operation));
		}
		return vp;
	}

	std::string basename(const std::string &fp) {
		std::size_t found = fp.find_last_of("/");
		if(found != std::string::npos) {
			return fp.substr(found+1);
		}
		return fp;
	}

	std::string samplename(const std::string &fp) {
		std::string base = basename(fp);
		std::size_t found = base.find_last_of(".");
		if(found != std::string::npos) {
			return base.substr(0,found);
		}
		return fp;	
	}
}
