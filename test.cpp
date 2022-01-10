#include <gtest/gtest.h>
#include <fstream>
#include "interpreter.h"

TEST(interpret, CorrectWorkAddNumber) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "2f r5 3 4 . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not number\nno such command: 'r5'\n4 3 not enough numbers ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkAdd) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "3 4 + . + . 3 + .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 7 not enough numbers\nnot enough numbers";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkSub) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "3 4 - . - . 3 - .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1 not enough numbers\nnot enough numbers";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkMod) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "10 13 % . % . 3 % .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 3 not enough numbers\nnot enough numbers";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkDiv) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "2 6 / . / . 3 / .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 3 not enough numbers\nnot enough numbers";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkMul) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "2 6 * . * . 3 * .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 12 not enough numbers\nnot enough numbers";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkMore) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "> 2 6 > 6 2 >";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0\n1 0 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkLess) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "< 2 6 < 6 2 <";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0\n1 0 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkEquals) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "= 2 2 = 2 6 =";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0\n1 0 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkDup) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "dup 2 dup . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\n2 2 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkDrop) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "drop 6 2 drop .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\n6 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkEmit) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "emit 65 emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\n A ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkSwap) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "swap 2 swap 3 swap . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\nnot enough numbers\n2 3 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkRot) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "rot 2 rot 3 rot 4 rot . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\nnot enough numbers\nnot enough numbers\n3 2 4 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while (res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkOver) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = "over 2 over 3 over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\nnot enough numbers\nnot enough numbers\n2 3 2 ";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkCr) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = ".cr. 2 .cr. 3 cr. .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> not enough numbers\nnot enough numbers\n3\n2 not enough numbers\n";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}

TEST(interpret, CorrectWorkPrintString) {
    std::ofstream out("C:\\Users\\bel_p\\CLionProjects\\interpretForthLike\\out.txt", std::ios::app);

    std::string str = ".\" wef awd\" .\" wef awd";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> wef awd not at the end of the line closing parenthesis\n";
    auto exp_it = expected.begin();
    auto res_it = result.begin();

    while(res_it != result.end()) {
        EXPECT_EQ(*exp_it, *res_it);
        exp_it++;
        res_it++;
    }
}
