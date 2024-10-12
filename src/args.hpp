#pragma once

#include <string>
#include <tuple>

typedef std::tuple<bool, int> arg_type;

class Args {
	public:
		int font_size;
		int border;
		int baselineskip;
		std::string fg;
		std::string bg;
		std::string latex_exp;
		std::string output_fname;
		Args(int font_size, int border, int baselineskip, std::string fg, std::string bg, std::string latex_exp, std::string fname);
};

std::string read_file(std::string filename);
arg_type exists(std::string valid_args[5], std::string args);
Args set_args(int argc, char* argv[]);
