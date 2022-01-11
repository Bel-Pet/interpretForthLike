#include <gtest/gtest.h>
#include <fstream>
#include "interpreter.h"

TEST(interpret, CorrectWorkAddNumber) {
    std::string str = "5 -2 4 . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 4 -2 5";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, NotCommand) {
    std::string str = "d4 5f 4 . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nno such command: 'd4'";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkAddNumber) {
    std::string str = "5f 4 . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nNot number: 5f";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkPoint) {
    std::string str = ". .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError point: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkAdd) {
    std::string str = "3 4 + .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 7";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkAddOneNumber) {
    std::string str = "3 + .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkAddZeroNumber) {
    std::string str = "+ .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkSub) {
    std::string str = "3 4 - .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkSubOneNumber) {
    std::string str = "3 - .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkSubZeroNumber) {
    std::string str = "- .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMod) {
    std::string str = "3 4 % .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkModOneNumber) {
    std::string str = "3 % .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkModZeroNumber) {
    std::string str = "% .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkModOneNumberZero) {
    std::string str = "3 0 % .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError mod: first number is null";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDiv) {
    std::string str = "3 4 / .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkDivOneNumber) {
    std::string str = "3 / .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkDivZeroNumber) {
    std::string str = "/ .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkDivOneNumberZero) {
    std::string str = "3 0 / .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError mod: first number is null";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMul) {
    std::string str = "3 4 * .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 12";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkMulOneNumber) {
    std::string str = "3 * .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkMulZeroNumber) {
    std::string str = "* .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError arithmetic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkMore) {
    std::string str = "2 6 > 6 2 >";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 1 0";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkMoreOneNumber) {
    std::string str = ">";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkMoreZeroNumber) {
    std::string str = "1 >";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkLess) {
    std::string str = "2 6 < 6 2 <";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0 1";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkLessOneNumber) {
    std::string str = "<";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkLessZeroNumber) {
    std::string str = "1 <";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkEquals) {
    std::string str = "2 6 = 7 7 =";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 0 1";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkEqualsOneNumber) {
    std::string str = "=";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkEqualsZeroNumber) {
    std::string str = "1 =";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError logic operation: not enough numbers";
    std::cout<<result<<std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDup) {
    std::string str = "2 dup . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 2 2";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkDup) {
    std::string str = "dup 2 dup . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError optional operator: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkDrop) {
    std::string str = "2  4 drop .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 2";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkDrop) {
    std::string str = "drop . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError optional operator: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkEmit) {
    std::string str = "65 emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> A";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkEmitNoNumber) {
    std::string str = "emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError emit: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkEmitNotAscii) {
    std::string str = "-2 emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError emit: going out of bounds";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkSwap) {
    std::string str = "2 3 swap . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 2 3";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkSwapNoNumber) {
    std::string str = "3 swap . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError swap: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkRot) {
    std::string str = "2 3 4 rot . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 3 2 4";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkRotNoNumber) {
    std::string str = "3 4 rot . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError rot: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkOver) {
    std::string str = "2 3 over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 2 3 2";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkOverNoNumbers) {
    std::string str = "over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError over: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkOverOneNumber) {
    std::string str = "1 over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError over: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkCr) {
    std::string str = " 23 45 . cr .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> 45\n 23";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, CorrectWorkPrintString) {
    std::string str = ".\" wef awd\"";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = "> wef awd";
    std::cout << result << std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, AncorrectWorkPrintString) {
    std::string str = ".\" wef awd";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError .\": no \"";
    std::cout << result << std::endl;
    bool check = result == expected;
    EXPECT_TRUE(check);
}
