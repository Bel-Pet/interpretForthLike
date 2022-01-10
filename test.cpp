#include <gtest/gtest.h>
#include <fstream>
#include "interpreter.h"

TEST(interpret, CorrectWorkAddNumber) {
    std::string str = "d4 5f 4 . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n no such command: 'd4'\n not number 4\n not enough numbers";
std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkAdd) {
    std::string str = "3 4 + . + . 3 + .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 7\n not enough numbers\n not enough numbers\n not enough numbers 3";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkSub) {
    std::string str = "3 4 - . - . 3 - .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1\n not enough numbers\n not enough numbers\n not enough numbers 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMod) {
    std::string str = "10 13 % . % . 3 % .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 3\n not enough numbers\n not enough numbers\n not enough numbers 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDiv) {
    std::string str = "2 6 / . / . 3 / .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 3\n not enough numbers\n not enough numbers\n not enough numbers 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMul) {
    std::string str = "2 6 * . * 3 * .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 12\n not enough numbers\n not enough numbers 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMore) {
    std::string str = "> 2 6 > 6 2 >";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0 1 0";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkLess) {
    std::string str = "< 2 6 < 6 2 <";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0 0 1";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkEquals) {
    std::string str = "= 2 2 = 2 6 =";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0 1 0";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDup) {
    std::string str = "dup 2 dup . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers 2 2";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDrop) {
    std::string str = "drop 6 2 drop .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers 6";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkEmit) {
    std::string str = "emit 65 emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers A";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkSwap) {
    std::string str = "swap 2 swap 3 swap . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers\n not enough numbers 2 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkRot) {
    std::string str = "rot 2 rot 3 rot 4 rot . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers\n not enough numbers\n not enough numbers 3 2 4";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkOver) {
    std::string str = "over 2 over 3 over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers\n not enough numbers 2 3 2";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkCr) {
    std::string str = ".cr. 2 .cr. 3 .cr. .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\n not enough numbers\n not enough numbers 3\n 2\n not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkPrintString) {
    std::string str = ".\" wef awd\" .\" wef awd";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> wef awd\n not at the end of the line closing parenthesis";
    std::cout << result << std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}
