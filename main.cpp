#include <string>
#include <iostream>
#include "interpreter.h"

int main(int argc, char const *argv[]) {

    std::string cmds;
    Interpreter & interpreter = Interpreter::getInstance();
    while (true) {
        std::cout << "> ";
        std::getline(std::cin , cmds);
        std::cout << '>' << interpreter.interpret(cmds)<< std::endl;
    }
    return 0;
}