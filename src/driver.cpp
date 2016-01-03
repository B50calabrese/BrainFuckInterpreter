#include "base/BFInterpreter.h"
#include "util/FileUtil.h"

#include <iostream>
#include <string>

/**
 * Main driver file for the brainfuck interpreter.
 */
int main(int argc, char *argv[]) {
	// If the user doesn't provide a file to be interpreted then we should exit.
	if (argc < 2) {
		std::cout << "User must provide an input file. Exitting.\n";
		return 1;
	}
	std::string fileContents = fileutil::readContent(argv[1]);
	
	if (fileContents == "") {
		std::cout << "File not correctly opened, exitting.\n";
		return 1;
	}
	
	interpreter::Interpreter vm(fileContents);
	vm.interpret();
	
	return 0;
}