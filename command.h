#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include "int_stack.h"
#include "interpreter_error.h"

class Command {
public:
    virtual ~Command()= default;
    virtual void apply(Context& x) = 0;
};

class ArithCommand: public Command {
public:
    // Performs an operation on the two elements at the top of the stack
    // Throw interpreter_error if there are less than two numbers on stack throw interpreter_error
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.stack.pop();

        int b = x.stack.pop();
        x.stack.push(op(a, b));
    }

    virtual int op(int& a, int& b)  = 0;
};

class Add: public ArithCommand {
    int op(int& a, int& b) override {
        return a + b;
    }
};

class Sub: public ArithCommand {
    int op(int& a, int& b)  override {
        return a - b;
    }
};

class Mul: public ArithCommand {
    int op(int& a, int& b)  override {
        return a * b;
    }
};

class Mod: public ArithCommand {
public:
    // Throw interpreter_error if the first number on the stack is zero
    void apply(Context& x)  override {
        if (!x.stack.empty() && x.stack.peek() == 0)
            throw interpreter_error("Error mod: first number is null");
        ArithCommand::apply(x);
    }
    int op(int& a, int& b)  override {
        return a % b;
    }
};

class Div: public ArithCommand {
    // Throw interpreter_error if the first number on the stack is zero
    void apply(Context& x)  override {
        if (!x.stack.empty() && x.stack.peek() == 0)
            throw interpreter_error("Error div: first number is null");
        ArithCommand::apply(x);
    }
    int op(int& a, int& b)  override {
        return a / b;
    }
};

class More: public ArithCommand {
    int op(int& a, int& b)  override {
        return a > b;
    }
};

class Less: public ArithCommand {
    int op(int& a, int& b)  override {
        return a < b;
    }
};

class Equals: public ArithCommand {
    int op(int& a, int& b)  override {
        return a == b;
    }
};

class Dup: public Command {
    // Copy the first number on the stack to the top of the stack
    // Throw interpreter_error if stack is empty
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.push(x.stack.peek());
    }
};

class Drop: public Command {
    // Removes the first number from the stack
    // Throw interpreter_error if stack is empty
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.pop();
    }
};

class Swap: public Command {
public:
    // Swap two top numbers on the stack
    // Throw interpreter_error if there are not enough numbers
    void apply(Context& x)  override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error swap: not enough numbers");

        x.stack.swap(1, 2);
    }
};

class Rot: public Command {
public:
    // Rot three top numbers on the stack
    // Example: 1 2 3 -> 3 1 2
    // Throw interpreter_error if there are not enough numbers
    void apply(Context& x)  override {
        if (x.stack.size() < 3)
            throw interpreter_error("Error rot: not enough numbers");

        x.stack.swap(1, 3);
        x.stack.swap(1, 2);
    }
};

class Over: public Command {
public:
    // Push the second number on the stack on top of the stack
    // Throw interpreter_error if it does not exist
    void apply(Context& x)  override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error over: not enough numbers");

        x.stack.push(x.stack.at(2));
    }
};

class Cr: public Command {
public:
    // Print '\n'
    void apply(Context& x)  override {
        x.result << '\n';
    }
};

class Point: public Command {
public:
    // Print top number on the stack
    // Throw interpreter_error if stack is empty
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error point: not enough numbers");

        x.result << " " << x.stack.peek();
        x.stack.pop();
    }
};

class Emit: public Command {
public:
    // Print number how ASCII character
    // throw interpreter_error if stack is empty or number on stack is out of ASCII range
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error emit: not enough numbers");

        int a = x.stack.pop();
        if (a < 0 || a > 255)
            throw interpreter_error("Error emit: number on stack is out of ASCII range");

        x.result << " " << (char)a;
    }
};

class PrintString: public Command {
public:
    // Print string in brackets
    // Throw interpreter_error if there is no closing bracket
    // Symbol " cannot be printed
    void apply(Context& x)  override {
        std::string str;
        for (; x.it < x.end && *x.it != '"'; x.it++) {
            str += *x.it;
        }

        if (x.it == x.end)
            throw interpreter_error("Error .\": no \"");

        x.it++;
        x.result << str;
    }
};

#endif