#include "command.h"
#include "interpreter.h"

namespace {

    bool add_cmd = Interpreter::getInstance().registerCreator("+", new Add());

    bool sub_cmd = Interpreter::getInstance().registerCreator("-", new Sub());

    bool mod_cmd = Interpreter::getInstance().registerCreator("%", new Mod());

    bool div_cmd = Interpreter::getInstance().registerCreator("/", new Div());

    bool mul_cmd = Interpreter::getInstance().registerCreator("*", new Mul());

    bool more_cmd = Interpreter::getInstance().registerCreator(">", new More());

    bool less_cmd = Interpreter::getInstance().registerCreator("<", new Less());

    bool equals_cmd = Interpreter::getInstance().registerCreator("=", new Equals());

    bool dup_cmd = Interpreter::getInstance().registerCreator("dup", new Dup());

    bool drop_cmd = Interpreter::getInstance().registerCreator("drop", new Drop());

    bool point_cmd = Interpreter::getInstance().registerCreator(".", new Point());

    bool swap_cmd = Interpreter::getInstance().registerCreator("swap", new Swap());

    bool rot_cmd = Interpreter::getInstance().registerCreator("rot", new Rot());

    bool over_cmd = Interpreter::getInstance().registerCreator("over", new Over());

    bool emit_cmd = Interpreter::getInstance().registerCreator("emit", new Emit());

    bool cr_cmd = Interpreter::getInstance().registerCreator(".cr.", new Cr());

    bool zero_cmd = Interpreter::getInstance().registerCreator("0", new AddNumber());

    bool one_cmd = Interpreter::getInstance().registerCreator("1", new AddNumber());

    bool two_cmd = Interpreter::getInstance().registerCreator("2", new AddNumber());

    bool three_cmd = Interpreter::getInstance().registerCreator("3", new AddNumber());

    bool four_cmd = Interpreter::getInstance().registerCreator("4", new AddNumber());

    bool five_cmd = Interpreter::getInstance().registerCreator("5", new AddNumber());

    bool six_cmd = Interpreter::getInstance().registerCreator("6", new AddNumber());

    bool seven_cmd = Interpreter::getInstance().registerCreator("7", new AddNumber());

    bool eight_cmd = Interpreter::getInstance().registerCreator("8", new AddNumber());

    bool nine_cmd = Interpreter::getInstance().registerCreator("9", new AddNumber());

    bool print_string_cmd = Interpreter::getInstance().registerCreator(".\"", new PrintString());

   /*Command * if_creator(std::string::iterator & it, std::string::iterator & end) {
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
        if (!exist_then)
            throw interpreter_error("no then;");

        return new If(one_stack_command, two_stack_command, exist_else);
    }

    bool if_cmd = Interpreter::getInstance().registerCreator("if", new If(one_stack_command, two_stack_command, exist_else));

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

    bool cycle_cmd = Interpreter::getInstance().registerCreator("do", new Cycle(stack_command, i));*/

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
