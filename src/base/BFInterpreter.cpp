#include "base/BFInterpreter.h"

#include <iostream>

/**
 * Source file for the interpreter class.
 */
namespace interpreter {

	/**
	 * Constructor for the interpreter.
	 */
	Interpreter::Interpreter(std::string content) {
		instructions = content;
		instructionPointer = 0;
		dataPointer = 0;
		continuallyInterpret = true;
		
		for (int i = 0 ; i < 30000 ; i++) {
			data[i] = 0;
		}
	}
	
	/**
	 * Interprets the given input.
	 */
	void Interpreter::interpret() {
		// While we still have stuff to interpret and we haven't run off either end.
		char currentInstruction;
		while (instructionPointer < instructions.length() && instructionPointer >= 0) {
			currentInstruction = instructions.at(instructionPointer);
			// Here we will actually deal with each instruction.
			if (currentInstruction == '>') {
				dataPointer++;
				if (dataPointer >= 30000) {
					dataPointer = 0;
				}
			} else if (currentInstruction == '<') {
				dataPointer--;
				if (dataPointer < 0) {
					dataPointer = 29999;
				}
			} else if (currentInstruction == '+') {
				data[dataPointer] += 0x1;
			} else if (currentInstruction == '-') {
				data[dataPointer] -= 0x1;
			} else if (currentInstruction == '.') {
				std::cout << data[dataPointer];
			} else if (currentInstruction == ',') {
				std::cin >> data[dataPointer];
			} else if (currentInstruction == '[') {
				if (data[dataPointer] == 0) {
					instructionPointer += 1;
					
					// We need to find the matching bracket.
					int bracketsMismatched = 0;
					while (true) {
						if (bracketsMismatched == 0 && instructions.at(instructionPointer) == ']') {
							break;
						}
						
						if (instructions.at(instructionPointer) == ']') {
							bracketsMismatched -= 1;
						} else if (instructions.at(instructionPointer) == '[') {
							bracketsMismatched += 1;
						}
						
						instructionPointer += 1;
					}
				}
			} else if (currentInstruction == ']') {
				if (data[dataPointer] != 0) {
					instructionPointer -= 1;
					
					// We need to find the matching bracket.
					int bracketsMismatched = 0;
					while (true) {
						if (bracketsMismatched == 0 && instructions.at(instructionPointer) == '[') {
							break;
						}
						
						if (instructions.at(instructionPointer) == ']') {
							bracketsMismatched += 1;
						} else if (instructions.at(instructionPointer) == '[') {
							bracketsMismatched -= 1;
						}
						
						instructionPointer -= 1;
					}
				}
			}
					
			instructionPointer++;
		}
	}
}