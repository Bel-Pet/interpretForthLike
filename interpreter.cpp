#include "interpreter.h"
#include <utility>

bool Interpreter::registerCreator(const std::string& c, std::shared_ptr<Command> creator) {
    creators_[c] = std::move(creator);
    return true;
}

std::string Interpreter::interpret(std::string::iterator& it, std::string::iterator& end) {
    std::stringstream result;
    result << ">";
    while (it != end) {
        if (*it == ' '){
            it++;
            continue;
        }
        try {
            if (isdigit(*it) || (*it == '-' && isdigit(*(it + 1)))) {
                creators_["0"]->apply(data_, result, it, end);
                continue;
            }
            std::string str;
            for (; it < end && !std::isspace(*it); it++) {
                str += *it;
            }

            find_command(str)->apply(data_, result, it, end);
        } catch (interpreter_error & e) {
            result << '\n' << e.what();
            break;
        }
    }
    return result.str();
}

std::shared_ptr<Command> Interpreter::find_command( const std::string& str) {
    auto creators_it = creators_.find(str);
    if (creators_it == creators_.end())
        throw interpreter_error("no such command: '" + str + "'");

    return creators_it->second;
}
