#include "latex2img.hpp"
#include "args.hpp"
#include "generate_latex_file.hpp"
#include <cstdlib>
#include <iostream>

void latex2img(int argc, char* argv[]) {
	Args args = set_args(argc, argv);
	generate_tex_file(args);
	std::string cmd;
	cmd = "pdflatex " + args.output_fname + ".tex";
	system(cmd.c_str());
	std::cout << "\n" << args.output_fname << ".pdf generated.\n";
	std::cout << "Removing temporary files...";
	cmd = "rm " + args.output_fname + ".tex";
	system(cmd.c_str());
	cmd = "rm " + args.output_fname + ".log";
	system(cmd.c_str());
	cmd = "rm " + args.output_fname + ".aux";
	system(cmd.c_str());
}
