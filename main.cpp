#include <iostream>
#include <sstream>
#include "Interpreter.h"

int main () {
    std::string line;

    Interpreter interpreter;
    while(std::getline(std::cin, line)) {

        if (line == "exit") {
            break;
        }

        try {
            std::cout << interpreter.execute(line.c_str()) << std::endl;
        } catch (const char *message) {
            std::cout << "[PARSE ERROR]: " << message << std::endl;
        }
    }

    return 0;

}