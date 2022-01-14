#include "interpreter.h"
#include <algorithm>
#include <stdexcept>

bool Interpreter::registerCreator(const std::string& c, Command* creator) {
    creators_[c].reset(creator);
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
            if (isdigit(*it) || (*it == '-' && isdigit(*(it + 1)))) {
                try {
                    add_number(it, end);
                }
                catch (std::out_of_range& e){
                    a.result << "out_of_range stoi";
                    break;
                }
                continue;
            }

            std::string key;
            for (; it < end && !std::isspace(*it); it++) {
                key += *it;
            }
            find_command(key, a);
        }
        catch (interpreter_error & e) {
            a.result << "\n" << e.what();;
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

void Interpreter::add_number(std::string::iterator & it, std::string::iterator & end) {
    int x = 1;
    if (*it == '-') {
        x = -1;
        it++;
    }
    std::string::iterator end_word = std::find_if_not(it, end, [](char i){return std::isdigit(i);});
    if (end_word != end)
        if (!std::isspace(*end_word))
            throw interpreter_error("Not number");
    data_.push_back(std::stoi(std::string(it, end_word)) * x);
    it = end_word;
    /*for (; it < end && !std::isspace(*it) && !isdigit(*it); it++) {
        str += *it;
        if (!isdigit(*it))
            throw interpreter_error("Not number: " + str);
    }
    data_.push_back(std::stoi(str) * x);*/
}