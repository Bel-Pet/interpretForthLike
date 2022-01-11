#include "interpreter.h"

bool Interpreter::registerCreator(const std::string& c, Command* creator) {
    creators_[c] = creator;
    return true;
}

std::string Interpreter::interpret(std::string::iterator& it, std::string::iterator& end) {
    std::stringstream result;
    result << ">";
    std::string str;
    while (it != end) {
        str.clear();
        // CR: https://en.cppreference.com/w/cpp/string/wide/iswspace
        if (*it == ' '){
            it++;
            continue;
        }
        try {
            // CR: negative values
            if (isdigit(*it)) {
                str = *it;
                creators_[str]->apply(data_, result, it, end);
                continue;
            }
            // CR: ::iswspace
            // CR: str += c as separate operation
            it = std::find_if(it, end, [&str](char c){ if (c == ' ') { return true; } str += c; return false;});
            // CR: use struct Context { data_, result, it, end }
            find_command(it, end, str, result)->apply(data_, result, it, end);
        } catch (interpreter_error & e) {
            result << '\n';
            result << e.what();
            // CR: stop execution on exception
        }
    }
    return result.str();
}

Command* Interpreter::find_command(std::string::iterator& it, std::string::iterator& end, const std::string& str, std::stringstream & result) {
    auto creators_it = creators_.find(str);
    if (creators_it == creators_.end()) {
        std::stringstream ss;
        ss << " no such command: '" << str << "'";
        throw interpreter_error(ss.str());
    }
    return creators_it->second;
}
