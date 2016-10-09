#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "fasta_reader.hpp"
#include "sam_reader.hpp"
#include "resistome.hpp"
#include "args.hpp"

using namespace std;

int main(const int argc, const char *argv[]) {
	if(argc != 15) {
		usage();
		exit(EXIT_FAILURE);
	}

	struct cmd_args args;
	args = parse_command_line(argc, argv);

	fasta_reader fr(args.ref_fp);
	map<string, record> records = fr.read();

	sam_reader sr(args.sam_fp);
	vector<struct alignment> alignments = sr.read();

	annotation_reader ar(args.annot_fp);
	map<string, annotation_fields> annotations = ar.read();

	resistome res;
	res.process_gene_level(records, alignments);
	res.process_resistome(records, annotations);
	res.write_resistome(args, utility::samplename(args.sam_fp), records);
	
	return 0;
}
