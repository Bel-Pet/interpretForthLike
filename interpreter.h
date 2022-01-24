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
    // Return result of commands execution
    // Break and write error to result if one of the commands failed
    std::string interpret(const std::string& str);
    Interpreter(Interpreter & other) = delete;
private:
    // Find and execute command
    // Throw interpreter_error if command does not exist
    void find_command(const std::string& key, Context& context);
    // Find a number
    // If number is found return true and push number on stack else return false
    bool add_number(std::string::const_iterator & it, std::string::const_iterator & end);
    Interpreter() = default;
    std::map<std::string, std::unique_ptr<Command>> creators_;
    IntStack data_;
};

#endif