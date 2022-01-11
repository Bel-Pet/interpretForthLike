#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <cctype>
#include <cstdlib>
#include "interpreter_error.h"

class Command {
public:
    virtual void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) = 0;
};

class Add: public Command {
public:
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        // CR: wrapper int_stack for vector
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a + b);
    }
};

class Sub: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a - b);
    }
};

#include <functional>

//class ArithCommand: public Command {
//    void apply(std::vector<int> &data, std::stringstream &result, std::string::iterator &it, std::string::iterator &end) override {
//        if (data.size() < 2)
//            throw interpreter_error(" not enough numbers");
//
//        int a  = data.back();
//        data.pop_back();
//        int b = data.back();
//        data.pop_back();
//        data.push_back(op()(a, b));
//    }
//
//    virtual std::function<int(int, int)> op() = 0;
//};
//
//class Sub1: public ArithCommand {
//    std::function<int(int, int)> op() override {
//        return std::minus();
//    }
//};


class Mod: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        // CR: check if second is null
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a % b);
    }
};

class Div: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        // CR: check if second is null
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a / b);
    }
};

class Mul: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a * b);
    }
};

// CR: Greater
class More: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        // CR: throw exception instead
        if (data.size() < 2 || *(data.end() - 1) < *(data.end() - 2)) {
            result << " 0";
            return;
        }
        result << " 1";
    }
};

class Less: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        // CR: same as More
        if (data.size() < 2 || *(data.end() - 1) > *(data.end() - 2)) {
            result << " 0";
            return;
        }
        result << " 1";
    }
};

class Equals: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        // CR: same
        if (data.size() < 2 || *(data.end() - 1) != *(data.end() - 2)) {
            result << " 0";
            return;
        }
        result << " 1";
    }
};

class Dup: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.empty())
            throw interpreter_error(" not enough numbers");

        data.push_back(data.back());
    }
};

class Drop: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        // CR: specify failed command
        if (data.empty())
            throw interpreter_error(" not enough numbers");

        data.pop_back();
    }
};

class Point: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.empty())
            throw interpreter_error(" not enough numbers");

        result << " " << data.back();
        data.pop_back();
    }
};

class Emit: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.empty())
            throw interpreter_error(" not enough numbers");

        // CR: check that number in ASCII range and throw if not
        result << " " << (char)data.back();
        data.pop_back();
    }
};

class Swap: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Rot: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 3)
            throw interpreter_error(" not enough numbers");

        std::swap(*(data.end() -1), *(data.end() -3));
        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Over: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        data.push_back(*(data.end() - 2));
    }
};

class Cr: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error(" not enough numbers");

        // CR: different logic
        result << " " << data.back() << '\n';
        data.pop_back();
        result << " " << data.back();
        data.pop_back();
    }
};

class AddNumber: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        std::string str;
        bool error = false;
        // CR: find_if / find_if_not?
        while (it != end && *it != ' ') {
            if (!isdigit(*it))
                error = true;
            str += *it;
            it++;
        }
        if (error)
            throw interpreter_error(" not number");
        data.push_back(std::stoi(str));
        //std::cout << data.back() << std::endl;
    }
};

class PrintString: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        it++;
        std::string str;
        // CR: find_if
        // CR: (optional) escape quotes ." \"foo" -> "foo; ." \\\\"" -> error
        while (it != end) {
            if (*it == '"')
                break;
            str += *it;
            it++;
        }
        if (it == end)
            throw interpreter_error(" no closing quote for string");

        it++;
        result << " " << str;
    }
};

/*class If: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.back() == 0) {
            if (exist_else_) {
                processing_command(else_stack_command_, data, result);
                return;
            }
            return;
        }
        processing_command(stack_command_, data, result);
    }
private:
    static void processing_command(std::vector<Command *>& stack, std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) {
        auto it_stack_command = stack.begin();
        while (it_stack_command != stack.end()) {
            (*it_stack_command)->apply(data, result, it, end);
            it_stack_command++;
        }
    }
    std::vector<Command *> stack_command_;
    std::vector<Command *> else_stack_command_;
    bool exist_else_;
};

class Cycle: public Command {
public:
    Cycle(std::vector<Command *>& stack_command, bool& i): stack_command_(stack_command), i_(i){}
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error("not enough numbers");

        int a, b;
        if (i_) {
            a = *(data.end() - 1);
            b = *(data.end() - 2);
            data.pop_back();
            data.pop_back();
        } else {
            a = *(data.end() - 2);
            b = *(data.end() - 1);
            data.pop_back();
        }
        while (a < b) {
            auto it_stack_command = stack_command_.begin();
            while (it_stack_command != stack_command_.end()) {
                (*it_stack_command)->apply(data, result, it, end);
                it_stack_command++;
            }
            a++;
        }
    }
private:
    std::vector<Command *> stack_command_;
    bool i_;
};*/

/*class NewCommand: public Command {
public:
    explicit NewCommand(std::vector<Command *>& stack) : stack_command_(stack){}
    void apply(std::vector<int>& data) override {
        auto it = stack_command_.begin();
        while (it != stack_command_.end()) {
            (*it)->apply(data);
            it++;
        }
    }
    static std::map<std::string, std::vector<Command *>> command_map;
private:
    std::vector<Command *> stack_command_;
};

class AddCommand: public Command {
public:
    void apply(std::vector<int>& data) override {
    }
};*/

#endif
