#include "interpreter.h"
#include <algorithm>
#include <stdexcept>

bool Interpreter::registerCreator(const std::string& c, std::unique_ptr<Command>&& creator) {
    creators_[c] = std::move(creator);
    return true;
}

std::string Interpreter::interpret(std::string& str) {
    auto it = str.begin();
    auto end = str.end();
    Context a(data_, it, end);
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
            find_command(key, a);
        }
        catch (interpreter_error & e) {
            a.result << "\n" << e.what();
            break;
        }
        catch (std::out_of_range& e){
            a.result << "\n" << e.what();
            break;
        }
    }
    return a.result.str();
}

void Interpreter::find_command(const std::string& key, Context& a) {
    auto creators_it = creators_.find(key);
    if (creators_it == creators_.end())
        throw interpreter_error("no such command: '" + key + "'");

    creators_it->second->apply(a);
}

bool Interpreter::add_number(std::string::iterator & it, std::string::iterator & end) {
    std::string::iterator digits_it = it;
    if (*digits_it == '-') digits_it++;
    if (digits_it == end || !std::isdigit(*digits_it)) return false;
    std::string::iterator end_digits = std::find_if_not(digits_it, end, ::isdigit);
    if (end_digits != end && !std::isspace(*end_digits))
        return false;
    data_.push(std::stoi(std::string(it, end_digits)));
    it = end_digits;
    return true;
}