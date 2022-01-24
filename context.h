#ifndef INTERPRETFORTHLIKE_CONTEXT_H
#define INTERPRETFORTHLIKE_CONTEXT_H

#include <sstream>
#include "int_stack.h"

struct Context {
    Context(IntStack& data_, std::string::const_iterator &it, const std::string::const_iterator &end) : stack(data_), it(it), end(end) {}
    // Value stack
    IntStack& stack;
    // Begin iterator of the command line
    std::string::const_iterator& it;
    // End iterator of the command line
    const std::string::const_iterator& end;
    // Result command execution
    std::stringstream result;
};

#endif