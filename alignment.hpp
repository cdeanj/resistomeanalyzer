#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>
#include <vector>
#include <utility>

struct alignment {
	int pos;
	int flag;
	std::string seq;
	std::string rname;
	std::vector<std::pair<int,char> > cigar;
};

#endif // ALIGNMENT_H
