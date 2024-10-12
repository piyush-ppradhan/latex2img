#include "args.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

const int n_arguments = 6;
const std::string valid_args[n_arguments]= {
	"-bg",
	"-fg",
	"-font_size",
	"-border",
	"-baselineskip",
	"-preview"
};

Args::Args(bool preview, int font_size, int border, int baselineskip, std::string fg, std::string bg, std::string latex_exp, std::string fname) {
	this->preview = preview;
	this->font_size = font_size;
	this->border = border;
	this->baselineskip = baselineskip;
	this->fg = fg;
	this->bg = bg;
	this->latex_exp = latex_exp;
	this->output_fname = fname;
}

std::string read_file(std::string filename) {
	std::ifstream t(filename.c_str());
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

arg_type check_exists(std::string args) {
	for (auto i = 0; i < n_arguments; ++i) {
		if (valid_args[i] == args) {
			return arg_type(true, i);
		}
	}
	return arg_type(false, 0);
}

int get_location(int argc, char* argv[], std::string arg) {
	for (auto i = 0; i < argc; ++i) {
		if (std::string(argv[i]) == arg) {
			return i+1;
		}
	}
	return -1;
}

Args set_args(int argc, char* argv[]) {

	// Default values
	int font_size = 12, border_size = 0, baselineskip=0;
	std::string fg = "#000000", bg = "#ffffff", latex_exp = "", fname="generated_expression";
	bool preview = false;

	bool baselineskip_set = false;

	// Get font size, foreground & background color
	for(int i = 1; i < argc-1; ++i) {
		auto res = check_exists(std::string(argv[i]));
		auto exists = std::get<bool>(res);
		auto pos = std::get<int>(res);
		if (exists) {
			switch (pos) {
				case 0: {
					bg = std::string(argv[i+1]);
					break;
				}
				case 1: {
					fg = std::string(argv[i+1]);
					break;
				}
				case 2: {
					font_size = std::atoi(argv[i+1]);
					break;
				}
				case 3: {
					border_size = std::atoi(argv[i+1]);
					break;
				}
				case 4: {
					baselineskip = std::atoi(argv[i+1]);
					baselineskip_set = true;
					break;
				}
				case 5: {
					preview = std::atoi(argv[i+1]);
					break;
				}
			}
		}
	}

	if (!baselineskip_set) {
		baselineskip = font_size + 4;
	}

	// Get latex expression
	auto res1 = get_location(argc, argv, std::string("-file"));
	auto res2 = get_location(argc, argv, std::string("-string"));
	if (res1 == -1) {
		if (res2 == -1) {
			std::cerr << "Latex expression source not specified";
			exit(1);
		}
		else {
			latex_exp = std::string(argv[res2]);
		}	
	}
	else {
		latex_exp = read_file(std::string(argv[res1]));
	}

	// Get output filename
	res1 = get_location(argc, argv, std::string("-output"));
	if (res1 != -1) {
		fname = std::string(argv[res1]);
	}
	return Args(preview, font_size, border_size, baselineskip, fg, bg, latex_exp, fname);
}
