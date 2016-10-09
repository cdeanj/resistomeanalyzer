#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>
#include <stdlib.h>

struct cmd_args {
	std::string ref_fp;
	std::string annot_fp;
	std::string sam_fp;
};

static void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: ResistomeAnalyzer \n");
        fprintf(stderr, "Contact: Chris Dean <cdean11@rams.colostate.edu>\n\n");
        fprintf(stderr, "Usage: rsa [options]\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "	-ref_fp		STR/FILE		fasta file path\n");
	fprintf(stderr, "	-annot_fp	STR/FILE		annotation file path\n");
        fprintf(stderr, "	-sam_fp		STR/FILE		sam file path\n");
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
                else {
                        usage();
                        exit(EXIT_FAILURE);
                }
        }
	return arg;
}

#endif // ARGS_H
