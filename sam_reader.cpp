#include "sam_reader.hpp"
#include "alignment.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace utility;

sam_reader::sam_reader(std::string fp) : _fp(fp) {}

std::vector<struct alignment> sam_reader::read() {
	std::ifstream ifs(_fp);
	if(!ifs) {
		std::cerr << "Unable to open sam file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::vector<struct alignment> alignments;
	while(std::getline(ifs, line)) {
		if(line[0] != '@') {
			struct alignment a;
			if(is_valid_alignment(line)) {
				init_alignment(&a,line);
				alignments.push_back(a);				
			}
		}
	}
	ifs.close();
	return alignments;
}
