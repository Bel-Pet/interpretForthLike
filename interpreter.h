#ifndef INTERPRETFORTHLIKE_INTERPRETER_H
#define INTERPRETFORTHLIKE_INTERPRETER_H

#include <map>
#include <fstream>
#include <memory>
#include "command.h"

class Interpreter {
public:
    static Interpreter & getInstance() {
        static Interpreter i;
        return i;
    }
    // Adds a command to the commands map
    bool registerCreator(const std::string& c, std::shared_ptr<Command> creator_t);
    // Translates a string into commands and fulfills them
    std::string interpret(std::string::iterator& it, std::string::iterator& end);
private:
    // Find and return command else return error
    std::shared_ptr<Command> find_command( const std::string& str);
    Interpreter() = default;
    std::map<std::string, std::shared_ptr<Command>> creators_;
    Data data_;
};

#endif

