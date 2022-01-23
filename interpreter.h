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
    // Translates a string into commands, executes them and writes result into string
    // Return result else throw interpreter_error if command is invalid
    std::string interpret(std::string& str);
    Interpreter(Interpreter & other) = delete;
private:
    // Find and execute command
    // Throw interpreter_error if command does not exist
    void find_command(const std::string& key, Context& a);
    // Find a number
    // If number is found return true and push number on stack else return false
    bool add_number(std::string::iterator & it, std::string::iterator & end);
    Interpreter() = default;
    std::map<std::string, std::unique_ptr<Command>> creators_;
    IntStack data_;
};

#endif