#ifndef INTERPRETFORTHLIKE_INTERPRETER_H
#define INTERPRETFORTHLIKE_INTERPRETER_H

#include <map>
#include "command.h"

class Interpreter {
public:
    static Interpreter & getInstance() {
        static Interpreter i;
        return i;
    }
    typedef Command * (*creator_t)(std::string::iterator & it, std::string::iterator & en);
    // Adds a command to the commands map
    bool registerCreator(const std::string& c, creator_t creator);
    // Translates a string into commands and fulfills them
    void interpret(std::string::iterator& it, std::string::iterator& end);
    // Find and return command else return error
    Command* find_command(std::string::iterator& it, std::string::iterator& end, const std::string& str);
    // Find and return word from string
    std::string find_str(std::string::iterator& it, std::string::iterator& end);
private:
    Interpreter() = default;
    std::map<std::string , creator_t> creators_;
    std::vector<int> data_;
};

#endif

