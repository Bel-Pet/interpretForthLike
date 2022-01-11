#ifndef INTERPRETFORTHLIKE_INTERPRETER_H
#define INTERPRETFORTHLIKE_INTERPRETER_H

#include <map>
#include "command.h"
#include <fstream>

class Interpreter {
public:
    static Interpreter & getInstance() {
        static Interpreter i;
        return i;
    }
    // Adds a command to the commands map
    bool registerCreator(const std::string& c, Command* creator_t);
    // Translates a string into commands and fulfills them
    std::string interpret(std::string::iterator& it, std::string::iterator& end);
private:
    // Find and return command else return error
    Command* find_command(std::string::iterator& it, std::string::iterator& end, const std::string& str, std::stringstream& result);
    Interpreter() = default;
    std::map<std::string, Command*> creators_;
    std::vector<int> data_;
};

#endif

