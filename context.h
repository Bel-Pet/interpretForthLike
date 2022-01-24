#ifndef INTERPRETFORTHLIKE_CONTEXT_H
#define INTERPRETFORTHLIKE_CONTEXT_H

#include <sstream>
#include "int_stack.h"

struct Context {
    Context(IntStack& data_, std::string::const_iterator &it, const std::string::const_iterator &end) : stack(data_), it(it), end(end) {}
    IntStack& stack;
    std::string::const_iterator& it;
    const std::string::const_iterator& end;
    std::stringstream result;
};

#endif //INTERPRETFORTHLIKE_CONTEXT_H
