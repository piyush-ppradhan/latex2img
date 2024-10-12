#include "generate_latex_file.hpp"
#include <iostream>
#include <fstream>
#include <string>

void generate_tex_file(Args args) {
	std::ofstream f;
	std::string line;
	f.open(args.output_fname + ".tex");
	if (!f) {
		std::cerr << "Cannot create file: " << args.output_fname << ".tex \n";
		exit(1);
	}

	if (!args.preview) {
		line = "\\documentclass";
	}
	else {
		line = "\\documentclass[preview]";
	}
	line = line + "{standalone}\n\\usepackage{xcolor, amsmath}\n\\standaloneconfig{margin=" + std::to_string(args.border) + "cm}\n";

	line = line + "\\definecolor{fg}{HTML}{" + args.fg.substr(1) + "}\n";
	line = line + "\\definecolor{bg}{HTML}{" + args.bg.substr(1) + "}\n";
	line = line + "\\begin{document}\n";
	line = line + "\\pagecolor{bg}\n";
	line = line + "\\color{fg}\n";
	line = line + "\\fontsize{" + std::to_string(args.font_size) + "}{" + std::to_string(args.baselineskip) + "}\\selectfont\n";
	line = line + args.latex_exp + "\n";

	line = line + "\\end{document}";
	f << line.c_str();
	f.close();
	std::cout << "File " << args.output_fname << ".tex generated.";
}
