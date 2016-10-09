#include "record.hpp"

record::record(std::string gene, int n) : _gene(gene), _base_hits(n, 0), _gene_hits(0) {}

double record::coverage() {
	return static_cast<double>(get_base_hits())/static_cast<double>(_gene.length())*100;
}

void record::reset_base_hits() {
        for(int i = 0; i < _base_hits.size(); i++) {
                _base_hits[i] = 0;
        }
}
