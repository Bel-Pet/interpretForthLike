#include <algorithm>
#include <stdexcept>
#include "interpreter.h"

bool Interpreter::registerCreator(const std::string& c, std::unique_ptr<Command>&& creator) {
    creators_[c] = std::move(creator);
    return true;
}

std::string Interpreter::interpret(const std::string& str) {
    auto it = str.begin();
    auto end = str.end();
    Context context(data_, it, end);
    while (it != end) {
        if (std::isspace(*it)){
            it++;
            continue;
        }
        try {
            if (add_number(it, end))
                continue;
            // Find key for map
            std::string key;
            for (; it < end && !std::isspace(*it); it++) {
                key += *it;
            }
            find_command(key, context);
        }
        catch (interpreter_error & e) {
            context.result << "\n" << e.what();
            break;
        }
        catch (std::out_of_range& e){
            context.result << "\n" << "out_of_range stoi";
            break;
        }
    }
    return context.result.str();
}

void Interpreter::find_command(const std::string& key, Context& context) {
    auto creators_it = creators_.find(key);
    if (creators_it == creators_.end())
        throw interpreter_error("no such command: '" + key + "'");

    creators_it->second->apply(context);
}

bool Interpreter::add_number(std::string::const_iterator & it, std::string::const_iterator & end) {
    std::string::const_iterator digits_it = it;
    if (*digits_it == '-') digits_it++;
    if (digits_it == end || !std::isdigit(*digits_it)) return false;
    std::string::const_iterator end_digits = std::find_if_not(digits_it, end, ::isdigit);
    if (end_digits != end && !std::isspace(*end_digits))
        return false;
    data_.push(std::stoi(std::string(it, end_digits)));
    it = end_digits;
    return true;
}