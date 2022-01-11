#include <string>
#include <iostream>
#include <fstream>
#include "interpreter.h"

int main(int argc, char const *argv[]) {
    std::ifstream file("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\file.txt");

    if (!file) {
        std::cout << "Error file";
        return 0;
    }

    std::string cmds;
    Interpreter interpreter = Interpreter::getInstance();
    while (std::getline(file, cmds, '\n')) {
        auto begin = cmds.begin();
        auto end = cmds.end();
        interpreter.interpret(begin, end);
    }
    file.close();
    return 0;
}
