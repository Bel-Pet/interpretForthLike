#include "command.h"
#include "interpreter.h"

namespace {

    Command * add_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Add();
    }

    bool add_cmd = Interpreter::getInstance().registerCreator("+", add_creator);

    Command * sub_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Sub();
    }

    bool sub_cmd = Interpreter::getInstance().registerCreator("-", sub_creator);

    Command * mod_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Mod();
    }

    bool mod_cmd = Interpreter::getInstance().registerCreator("%", mod_creator);

    Command * div_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Div();
    }

    bool div_cmd = Interpreter::getInstance().registerCreator("/", div_creator);

    Command * mul_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Mul();
    }

    bool mul_cmd = Interpreter::getInstance().registerCreator("*", mul_creator);

    Command * more_creator(std::string::iterator & it, std::string::iterator & end) {
        return new More();
    }

    bool more_cmd = Interpreter::getInstance().registerCreator(">", more_creator);

    Command * less_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Less();
    }

    bool less_cmd = Interpreter::getInstance().registerCreator("<", less_creator);

    Command * equals_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Equals();
    }

    bool equals_cmd = Interpreter::getInstance().registerCreator("=", equals_creator);

    Command * dup_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Dup();
    }

    bool dup_cmd = Interpreter::getInstance().registerCreator("dup", dup_creator);

    Command * drop_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Drop();
    }

    bool drop_cmd = Interpreter::getInstance().registerCreator("drop", drop_creator);

    Command * point_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Point();
    }

    bool point_cmd = Interpreter::getInstance().registerCreator(".", point_creator);

    Command * swap_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Swap();
    }

    bool swap_cmd = Interpreter::getInstance().registerCreator("swap", swap_creator);

    Command * rot_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Rot();
    }

    bool rot_cmd = Interpreter::getInstance().registerCreator("rot", rot_creator);

    Command * over_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Over();
    }

    bool over_cmd = Interpreter::getInstance().registerCreator("over", over_creator);

    Command * emit_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Emit();
    }

    bool emit_cmd = Interpreter::getInstance().registerCreator("emit", emit_creator);

    Command * cr_creator(std::string::iterator & it, std::string::iterator & end) {
        return new Cr();
    }

    bool cr_cmd = Interpreter::getInstance().registerCreator(".cr.", cr_creator);

    Command * print_string_creator(std::string::iterator & it, std::string::iterator & end) {
        std::string str;
        while (it != end) {
            if (*it == '"')
                break;
            str += *it;
            it++;
        }
        if (it == end) {
            std::stringstream ss;
            ss << "not at the end of the line closing parenthesis";
            throw interpreter_error(ss.str());
        }
        it++;
        return new PrintString(str);
    }

    bool print_string_cmd = Interpreter::getInstance().registerCreator(".\"", print_string_creator);

    Command * add_number_creator(std::string::iterator & it, std::string::iterator & end) {
        int num = 0;
        bool false_number = false;
        while (it != end && *it != ' ') {
            if (!(*it >= '0' && *it <= '9')) {
                false_number = true;
            }
            num = num * 10 + (int) (*it - '0');
            it++;
        }
        if (false_number) {
            std::stringstream ss;
            ss << "not number";
            throw interpreter_error(ss.str());
        }
        return new AddNumber(num);
    }

    bool add_number_cmd = Interpreter::getInstance().registerCreator("0", add_number_creator);

   Command * if_creator(std::string::iterator & it, std::string::iterator & end) {
        std::vector<Command *> one_stack_command;
        std::vector<Command *> two_stack_command;
        bool exist_else = false;
        bool exist_then = false;
        while (it != end) {
            if (*it == ' '){
                it++;
                continue;
            }
            std::string str = Interpreter::getInstance().find_str(it, end);
            if (str == "else") {
                exist_else = true;
                continue;
            }
            if (str == "then;") {
                exist_then = true;
                break;
            }
            if (exist_else) {
                Command* creator = Interpreter::getInstance().find_command(it, end, str);
                two_stack_command.push_back(creator);
                continue;
            }
            Command* creator = Interpreter::getInstance().find_command(it, end, str);
            one_stack_command.push_back(creator);
        }
        if (!exist_then) {
            std::stringstream ss;
            ss << "no then;";
            throw interpreter_error(ss.str());
        }
        return new If(one_stack_command, two_stack_command, exist_else);
    }

    bool if_cmd = Interpreter::getInstance().registerCreator("if", if_creator);

    Command * cycle_creator(std::string::iterator & it, std::string::iterator & end) {
        std::vector<Command *> stack_command;
        bool i = false;
        bool exist_loop = false;
        while (it != end) {
            if (*it == ' '){
                it++;
                continue;
            }
            std::string str = Interpreter::getInstance().find_str(it, end);
            if (str == "loop;") {
                exist_loop = true;
                break;
            }
            Command* creator = Interpreter::getInstance().find_command(it, end, str);
            stack_command.push_back(creator);
        }
        if (!exist_loop) {
            std::stringstream ss;
            ss << "no then;";
            throw interpreter_error(ss.str());
        }
        return new Cycle(stack_command, i);
    }

    bool cycle_cmd = Interpreter::getInstance().registerCreator("do", cycle_creator);

    /*Command * new_command_creator(std::string::iterator & it, std::string::iterator & end) {
        std::string str;
        while (it != end && *it != ' ') {
            str += *it;
        }
        return new NewCommand(NewCommand::command_map[str]);
    }

    Command * add_command_creator(std::string::iterator & it, std::string::iterator & end) {
        std::string str;
        it++;
        while (it != end) {
            if (*it == ' '){
                it++;
                break;
            }
            str += *it;
        }
        if (str.empty()) {
            std::stringstream ss;
            ss << "no name new function";
            throw interpreter_error(ss.str());
        }
        std::vector<Command *> stack_command;
        while (it != end) {
            if (*it == ' '){
                it++;
                continue;
            }
            stack_command.push_back(Interpreter::getInstance().find_command(it, end, Interpreter::getInstance().find_str(it, end)));
        }
        if (stack_command.empty()) {
            std::stringstream ss;
            ss << "no commands in a function body";
            throw interpreter_error(ss.str());
        }
        return new AddCommand();
    }

    bool add_command_cmd = Interpreter::getInstance().registerCreator(":", add_command_creator);*/
}
