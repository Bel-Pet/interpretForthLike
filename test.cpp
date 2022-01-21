#include <gtest/gtest.h>
#include "interpreter.h"

TEST(interpret, CorrectWorkAddNumber) {
    std::string str = "5 -2 4 . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 4 -2 5");
}

TEST(interpret, NotCommand) {
    std::string str = "d4 5f 4 . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nno such command: 'd4'");
}

TEST(interpret, IncorrectWorkAddNumber) {
    std::string str = "5f 4 . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nno such command: '5f'");
}

// CR: add tests: overflow, only one number
TEST(interpret, CorrectWorkAdd) {
    std::string str = "3 4 + .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 7");
}

TEST(interpret, IncorrectWorkAddZeroNumber) {
    std::string str = "+ .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkSub) {
    std::string str = "3 4 - .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 1");
}

TEST(interpret, IncorrectWorkSubZeroNumber) {
    std::string str = "- .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkMod) {
    std::string str = "3 4 % .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 1");
}

TEST(interpret, IncorrectWorkModZeroNumber) {
    std::string str = "% .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, IncorrectWorkModOneNumberZero) {
    std::string str = "3 0 % .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError mod: first number is null");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 0 3");
}

TEST(interpret, CorrectWorkDiv) {
    std::string str = "3 4 / .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 1");
}

TEST(interpret, IncorrectWorkPoint) {
    std::string str = ".";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError point: not enough numbers");
}

TEST(interpret, IncorrectWorkDivZeroNumber) {
    std::string str = "/ .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, IncorrectWorkDivOneNumberZero) {
    std::string str = "3 0 / .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError div: first number is null");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 0 3");
}

TEST(interpret, CorrectWorkMul) {
    std::string str = "3 4 * .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 12");
}

TEST(interpret, IncorrectWorkMulZeroNumber) {
    std::string str = "* .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkMore) {
    std::string str = "2 6 > . 6 2 > .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 1 0");
}

TEST(interpret, IncorrectWorkMoreOneNumber) {
    std::string str = ">";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkLess) {
    std::string str = "2 6 < . 6 2 < .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 0 1");
}

TEST(interpret, IncorrectWorkLessOneNumber) {
    std::string str = "<";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkEquals) {
    std::string str = "2 6 = . 7 7 = .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 0 1");
}

TEST(interpret, IncorrectWorkEqualsOneNumber) {
    std::string str = "=";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, CorrectWorkDup) {
    std::string str = "2 dup . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 2 2");
}

TEST(interpret, IncorrectWorkDup) {
    std::string str = "dup 2 dup . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError optional operator: not enough numbers");
}

TEST(interpret, CorrectWorkDrop) {
    std::string str = "2 4 drop .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 2");
}

TEST(interpret, IncorrectWorkDrop) {
    std::string str = "drop . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError optional operator: not enough numbers");
}

TEST(interpret, CorrectWorkEmit) {
    std::string str = "65 emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " A");
}

TEST(interpret, IncorrectWorkEmitNoNumber) {
    std::string str = "emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError emit: not enough numbers");
}

TEST(interpret, IncorrectWorkEmitNotAscii) {
    std::string str = "-2 emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError emit: number on stack is out of ASCII range");
}

TEST(interpret, CorrectWorkSwap) {
    std::string str = "2 3 swap . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 2 3");
}

TEST(interpret, IncorrectWorkSwapNoNumber) {
    std::string str = "3 swap . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError swap: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 3");
}

TEST(interpret, CorrectWorkRot) {
    std::string str = "2 3 4 rot . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 3 2 4");
}

TEST(interpret, IncorrectWorkRotNoNumber) {
    std::string str = "3 4 rot . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError rot: not enough numbers");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 4 3");
}

TEST(interpret, CorrectWorkOver) {
    std::string str = "2 3 over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 2 3 2");
}

TEST(interpret, IncorrectWorkOverNoNumbers) {
    std::string str = "over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError over: not enough numbers");
}

TEST(interpret, IncorrectWorkOverOneNumber) {
    std::string str = "1 over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError over: not enough numbers");
}

TEST(interpret, CorrectWorkCr) {
    std::string str = " 23 45 . cr .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " 45\n 23");
}

// CR: test ." foo\" "

// CR: test if no space
TEST(interpret, CorrectWorkPrintString) {
    std::string str = ".\" wef awd\"";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == " wef awd");
}

TEST(interpret, IncorrectWorkPrintString) {
    std::string str = ".\" wef awd";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_TRUE(result == "\nError .\": no \"");
}
