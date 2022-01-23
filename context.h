#ifndef INTERPRETFORTHLIKE_CONTEXT_H
#define INTERPRETFORTHLIKE_CONTEXT_H

#include <sstream>
#include "int_stack.h"

struct  Context {
    Context(IntStack& data_, std::string::iterator &it, std::string::iterator &end) : stack(data_), it(it), end(end) {}
    IntStack& stack;
    std::string::iterator& it;
    const std::string::iterator& end;
    std::stringstream result;
};

#endif //INTERPRETFORTHLIKE_CONTEXT_H
