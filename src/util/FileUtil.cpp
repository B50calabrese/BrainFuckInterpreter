#include <fstream>
#include <iostream>
#include <string>

namespace fileutil {
	/**
	 * Contains useful file utility functions.
	 */
	 
	/**
	 * Reads the content of an input file.
	 * @param fileName the name of the input file.
	 * @return a string containing the entire file's contents.
	 */
	 std::string readContent(char* fileName) {
		std::ifstream file(fileName);
		
		// If the file doesn't exist, return null.
		if (!file) {
			return "";
		}
		
		std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

		return contents;
	 }
}