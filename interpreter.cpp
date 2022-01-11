#include "interpreter.h"
#include <utility>

bool Interpreter::registerCreator(const std::string& c, std::shared_ptr<Command> creator) {
    creators_[c] = std::move(creator);
    return true;
}

std::string Interpreter::interpret(std::string::iterator& it, std::string::iterator& end) {
    data_.it = it;
    data_.end = end;
    data_.result += '>';
    while (data_.it != data_.end) {
        if (*data_.it == ' '){
            data_.it++;
            continue;
        }
        try {
            if (isdigit(*data_.it) || (*data_.it == '-' && isdigit(*(data_.it + 1)))) {
                creators_["0"]->apply(data_);
                continue;
            }
            std::string str;
            for (; data_.it < data_.end && !std::isspace(*data_.it); data_.it++) {
                str += *data_.it;
            }

            find_command(str)->apply(data_);
        } catch (interpreter_error & e) {
            data_.result += "\n";
            data_.result += e.what();
            break;
        }
    }
    return data_.result;
}

std::shared_ptr<Command> Interpreter::find_command( const std::string& str) {
    auto creators_it = creators_.find(str);
    if (creators_it == creators_.end())
        throw interpreter_error("no such command: '" + str + "'");

    return creators_it->second;
}
