#ifndef ANNOTATION_READER_H
#define ANNOTATION_READER_H

#include <vector>
#include <string>
#include <map>

struct annotation_fields {
        annotation_fields() {}
        annotation_fields(std::string class_l, std::string mechanism_l, std::string group_l)
                : _class_l(class_l), _mechanism_l(mechanism_l), _group_l(group_l)
        {}

        std::string _class_l;
        std::string _mechanism_l;
        std::string _group_l;
};

class annotation_reader {
public:
	annotation_reader(std::string fp);
	std::map<std::string, annotation_fields> read();
private:
	std::string _fp;
};

#endif // ANNOTATION_READER_H
