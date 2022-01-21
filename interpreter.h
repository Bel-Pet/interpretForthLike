#ifndef INTERPRETFORTHLIKE_INTERPRETER_H
#define INTERPRETFORTHLIKE_INTERPRETER_H

#include <map>
#include <memory>
#include "command.h"

class Interpreter {
public:
    static Interpreter & getInstance() {
        static Interpreter i;
        return i;
    }
    // Adds a command to the commands map
    bool registerCreator(const std::string& c, std::unique_ptr<Command>&& creator);
    // Translates a string into commands and executes them
    std::string interpret(std::string& str);
    Interpreter(Interpreter & other) = delete;
private:
    // Find and return command
    // Else throw interpreter_error
    void find_command(const std::string& key, Context& a);
    // Push number on the data_
    // Else throw interpreter_error
    bool add_number(std::string::iterator & it, std::string::iterator & end);
    Interpreter() = default;
    std::map<std::string, std::unique_ptr<Command>> creators_;
    IntStack data_;
};

#endif