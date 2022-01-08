#ifndef INTERPRETFORTHLIKE_INTERPRETER_ERROR_H
#define INTERPRETFORTHLIKE_INTERPRETER_ERROR_H

#include <stdexcept>

class interpreter_error: public std::runtime_error {
public:
    explicit interpreter_error(const std::string& msg): std::runtime_error(msg) {}
};

#endif
