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

TEST(interpret, IncorrectWorkAddNumber) {
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

TEST(interpret, IncorrectWorkPoint) {
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

TEST(interpret, IncorrectWorkAddOneNumber) {
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

TEST(interpret, IncorrectWorkAddZeroNumber) {
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

TEST(interpret, IncorrectWorkSubOneNumber) {
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

TEST(interpret, IncorrectWorkSubZeroNumber) {
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

TEST(interpret, IncorrectWorkModOneNumber) {
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

TEST(interpret, IncorrectWorkModZeroNumber) {
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

TEST(interpret, IncorrectWorkModOneNumberZero) {
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

TEST(interpret, IncorrectWorkDivOneNumber) {
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

TEST(interpret, IncorrectWorkDivZeroNumber) {
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

TEST(interpret, IncorrectWorkDivOneNumberZero) {
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

TEST(interpret, IncorrectWorkMulOneNumber) {
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

TEST(interpret, IncorrectWorkMulZeroNumber) {
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

TEST(interpret, IncorrectWorkMoreOneNumber) {
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

TEST(interpret, IncorrectWorkMoreZeroNumber) {
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

TEST(interpret, IncorrectWorkLessOneNumber) {
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

TEST(interpret, IncorrectWorkLessZeroNumber) {
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

TEST(interpret, IncorrectWorkEqualsOneNumber) {
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

TEST(interpret, IncorrectWorkEqualsZeroNumber) {
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

TEST(interpret, IncorrectWorkDup) {
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

TEST(interpret, IncorrectWorkDrop) {
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

TEST(interpret, IncorrectWorkEmitNoNumber) {
    std::string str = "emit";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError emit: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, IncorrectWorkEmitNotAscii) {
    std::string str = "-2 emit";
    // CR: move to separate method
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError emit: going out of bounds of ASCII";

    // CR: EXPECT_EQ
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

TEST(interpret, IncorrectWorkSwapNoNumber) {
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

TEST(interpret, IncorrectWorkRotNoNumber) {
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

TEST(interpret, IncorrectWorkOverNoNumbers) {
    std::string str = "over . . .";
    auto it = str.begin();
    auto end = str.end();

    Interpreter interpreter = Interpreter::getInstance();
    std::string result = interpreter.interpret(it, end);

    std::string expected = ">\nError over: not enough numbers";

    bool check = result == expected;
    EXPECT_TRUE(check);
}

TEST(interpret, IncorrectWorkOverOneNumber) {
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

TEST(interpret, IncorrectWorkPrintString) {
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
