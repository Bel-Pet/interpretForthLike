#include <gtest/gtest.h>
#include "interpreter.h"

TEST(interpret, CorrectWorkAddNumber) {
    std::string str = "5 -2 4 . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 4 -2 5";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, NotCommand) {
    std::string str = "d4 5f 4 . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nno such command: 'd4'";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkAddNumber) {
    std::string str = "5f 4 . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nNot number";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, WorkAddNumber) {
    std::string str = "5";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);
    EXPECT_TRUE(result.empty());
}

TEST(interpret, AncorrectWorkPoint) {
    std::string str = ". .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError point: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkAdd) {
    std::string str = "3 4 + .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 7";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkAddOneNumber) {
    std::string str = "3 + .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkAddZeroNumber) {
    std::string str = "+ .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkSub) {
    std::string str = "3 4 - .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 1";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkSubOneNumber) {
    std::string str = "3 - .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkSubZeroNumber) {
    std::string str = "- .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkMod) {
    std::string str = "3 4 % .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 1";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkModOneNumber) {
    std::string str = "3 % .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkModZeroNumber) {
    std::string str = "% .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkModOneNumberZero) {
    std::string str = "3 0 % .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError mod: first number is null";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkDiv) {
    std::string str = "3 4 / .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 1";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkDivOneNumber) {
    std::string str = "3 / .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkDivZeroNumber) {
    std::string str = "/ .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkDivOneNumberZero) {
    std::string str = "3 0 / .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError div: first number is null";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkMul) {
    std::string str = "3 4 * .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 12";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkMulOneNumber) {
    std::string str = "3 * .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkMulZeroNumber) {
    std::string str = "* .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkMore) {
    std::string str = "2 6 > . 6 2 > .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 1 0";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkMoreOneNumber) {
    std::string str = ">";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkMoreZeroNumber) {
    std::string str = "1 >";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkLess) {
    std::string str = "2 6 < . 6 2 < .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 0 1";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkLessOneNumber) {
    std::string str = "<";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkLessZeroNumber) {
    std::string str = "1 <";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkEquals) {
    std::string str = "2 6 = . 7 7 = .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 0 1";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkEqualsOneNumber) {
    std::string str = "=";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkEqualsZeroNumber) {
    std::string str = "1 =";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError arithmetic operation: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkDup) {
    std::string str = "2 dup . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 2 2";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkDup) {
    std::string str = "dup 2 dup . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError optional operator: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkDrop) {
    std::string str = "2  4 drop .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 2";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkDrop) {
    std::string str = "drop . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError optional operator: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkEmit) {
    std::string str = "65 emit";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " A";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkEmitNoNumber) {
    std::string str = "emit";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError emit: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkEmitNotAscii) {
    std::string str = "-2 emit";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError emit: going out of bounds";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkSwap) {
    std::string str = "2 3 swap . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 2 3";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkSwapNoNumber) {
    std::string str = "3 swap . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);
std::cout<< result;
    std::string expected = "\nError swap: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkRot) {
    std::string str = "2 3 4 rot . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 3 2 4";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkRotNoNumber) {
    std::string str = "3 4 rot . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError rot: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkOver) {
    std::string str = "2 3 over . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 2 3 2";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkOverNoNumbers) {
    std::string str = "over . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError over: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkOverOneNumber) {
    std::string str = "1 over . . .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError over: not enough numbers";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkCr) {
    std::string str = " 23 45 . cr .";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " 45\n 23";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, CorrectWorkPrintString) {
    std::string str = ".\" wef awd\"";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = " wef awd";
    EXPECT_TRUE(result == expected);
}

TEST(interpret, AncorrectWorkPrintString) {
    std::string str = ".\" wef awd";
    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(str);

    std::string expected = "\nError .\": no \"";
    std::cout << result << std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}