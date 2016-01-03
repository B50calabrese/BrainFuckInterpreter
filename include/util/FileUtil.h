#ifndef UTIL_FILE_UTIL_H
#define UTIL_FILE_UTIL_H

#include <string>

namespace fileutil {

	/**
	 * Reads the content of an input file.
	 * @param fileName the name of the input file.
	 * @return a string containing the entire file's contents.
	 */
	std::string readContent(char* fileName);
}
	
#endif // UTIL_FILE_UTIL_H 