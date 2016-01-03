#ifndef BASE_BFINTERPRETER_H
#define BASE_BFINTERPRETER_H

#include <string>

namespace interpreter {
	
	/**
	 * Represents the internals of the brainfuck interpreter.
	 */
	class Interpreter {
		private:
			std::string instructions;
			int instructionPointer;
			int dataPointer;
			unsigned char data[30000];
			bool continuallyInterpret;
			
			// Constructor is private so that the user must give some content to be interpreted.
			Interpreter() {}
		
		public:
			Interpreter(std::string content);
			
			/**
			 * Used to start the interpreter.
			 */
			void interpret();
	};
}
	
#endif // BASE_BFINTERPRETER_H