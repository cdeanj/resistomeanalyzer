#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>
#include <algorithm>

class record {
public:
        record(std::string gene, int n);
	inline std::string get_gene() const { return _gene; }
	inline int get_base_hits() const { return static_cast<int>(count(_base_hits.begin(), _base_hits.end(), 1)); }
	inline int gene_hits() const { return _gene_hits; }
	inline void update_gene_hits() { _gene_hits++; }
	inline void reset_gene_hits() { _gene_hits = 0; }
	void reset_base_hits();
	double coverage();

        std::vector<int> _base_hits;
        std::string _gene;
	int _gene_hits;
};

#endif // RECORD_H
