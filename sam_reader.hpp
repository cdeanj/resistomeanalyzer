#ifndef SAM_READER_H
#define SAM_READER_H

#include <string>
#include <vector>
#include "alignment.hpp"
#include "utility.hpp"

class sam_reader {
public:
	sam_reader(std::string fp);
	std::vector<struct alignment> read();
private:
	std::string _fp;
};

#endif // SAM_READER_H
