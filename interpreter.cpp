#include "interpreter.h"

bool Interpreter::registerCreator(const std::string& c, creator_t creator) {
    creators_[c] = creator;
    return true;
}

void Interpreter::interpret(std::string::iterator& it, std::string::iterator& end) {
    while (it != end) {
        if (*it == ' '){
            it++;
            continue;
        }
        try {
            find_command(it, end, find_str(it, end))->apply(data_);
        } catch (interpreter_error & e) {
            std::cout << e.what() << std::endl;
        }
    }
}

Command* Interpreter::find_command(std::string::iterator& it, std::string::iterator& end, const std::string& str) {
    auto creators_it = creators_.find(str);
    if (creators_it == creators_.end()) {
        std::stringstream ss;
        ss << "no such command: '" << str << "'";
        throw interpreter_error(ss.str());
    }
    return creators_it->second(it, end);
}

std::string Interpreter::find_str(std::string::iterator& it, std::string::iterator& end) {
    std::string str;
    while (it != end && *it != ' ') {
        // Condition for finding the command to add a number to the stack
        if (*it >= '0' && *it <= '9' && str.empty()) {
            str = "0";
            break;
        }
        // Condition for finding the command to print a line
        if (str == ".\"" && *it == ' '){
            break;
        }
        str += *it;
        it++;
    }
    return str;
}
