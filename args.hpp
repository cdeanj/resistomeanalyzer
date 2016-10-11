#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>
#include <stdlib.h>

struct cmd_args {
	std::string ref_fp;
	std::string annot_fp;
	std::string sam_fp;
	std::string gene_fp;
	std::string mech_fp;
	std::string group_fp;
	std::string class_fp;
	int threshold;
};

static void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: ResistomeAnalyzer \n");
        fprintf(stderr, "Contact: Chris Dean <cdean11@rams.colostate.edu>\n\n");
        fprintf(stderr, "Usage: ./resistome [options]\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "	-ref_fp		STR/FILE	Fasta formatted reference sequence\n");
	fprintf(stderr, "	-annot_fp	STR/FILE	CSV formatted annotation database\n");
        fprintf(stderr, "	-sam_fp		STR/FILE	SAM formatted alignment file\n");
	fprintf(stderr, "	-gene_fp	STR/FILE	Output name for gene level resistome\n");
	fprintf(stderr, "	-group_fp	STR/FILE	Output name for group level resistome\n");
	fprintf(stderr, "	-mech_fp	STR/FILE	Output name for mechanism level resistome\n");
	fprintf(stderr, "	-class_fp	STR/FILE	Output name for class level resistome\n");
	fprintf(stderr, "	-t		INT		Gene fraction threshold\n\n");
}

struct cmd_args 
inline parse_command_line(const int argc, const char *argv[]) {
	struct cmd_args arg;
	std::vector<std::string> args(argv, argv + argc);

        for(int i = 1; i < argc; i++) {
                if(args[i].compare("-ref_fp") == 0)
                        arg.ref_fp = args[++i];
		else if(args[i].compare("-annot_fp") == 0)
			arg.annot_fp = args[++i];
                else if(args[i].compare("-sam_fp") == 0)
                        arg.sam_fp = args[++i];
		else if(args[i].compare("-gene_fp") == 0) {
			arg.gene_fp = args[++i];
		}
		else if(args[i].compare("-mech_fp") == 0) {
			arg.mech_fp = args[++i];
                }
		else if(args[i].compare("-group_fp") == 0) {
			arg.group_fp = args[++i];
                }
		else if(args[i].compare("-class_fp") == 0) {
			arg.class_fp = args[++i];
                }
		else if(args[i].compare("-t") == 0) {
			arg.threshold = atoi(args[++i].c_str());
		}
                else {
                        usage();
                        exit(EXIT_FAILURE);
                }
        }
	return arg;
}

#endif // ARGS_H
