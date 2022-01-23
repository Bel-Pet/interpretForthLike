#include <gtest/gtest.h>
#include "interpreter.h"

TEST(interpret, Correct_Work_Add_Number) {
    std::string str = "5 -2 4 . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 4 -2 5");
}

TEST(interpret, Not_Command) {
    std::string str = "d4 5f 4 . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nno such command: 'd4'");
}

TEST(interpret, Incorrect_Work_Add_Number) {
    std::string str = "5f 4 . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nno such command: '5f'");
}

TEST(interpret, Correct_Work_Add) {
    std::string str = "3 4 + .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 7");
}

TEST(interpret, Incorrect_Work_Add_One_Number) {
    std::string str = "1 + .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Add_Zero_Number) {
    std::string str = "+ .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Correct_Work_Sub) {
    std::string str = "3 4 - .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Sub_Zero_Number) {
    std::string str = "- .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Sub_One_Number) {
    std::string str = "1 - .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Correct_Work_Mod) {
    std::string str = "3 4 % .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Mod_Zero_Number) {
    std::string str = "% .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Mod_One_Number) {
    std::string str = "1 % .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Mod_One_Number_Zero) {
    std::string str = "3 0 % .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError mod: first number is null");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 0 3");
}

TEST(interpret, Correct_Work_Div) {
    std::string str = "3 4 / .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Point) {
    std::string str = ". .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError point: not enough numbers");
}

TEST(interpret, Incorrect_Work_Div_Zero_Number) {
    std::string str = "/ .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Div_One_Number) {
    std::string str = "1 / .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Incorrect_Work_Div_One_Number_Zero) {
    std::string str = "3 0 / .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError div: first number is null");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 0 3");
}

TEST(interpret, Correct_Work_Mul) {
    std::string str = "3 4 * .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 12");
}

TEST(interpret, Incorrect_Work_Mul_Zero_Number) {
    std::string str = "* .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Mul_One_Number) {
    std::string str = "1 * .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Correct_Work_More) {
    std::string str = "2 6 > . 6 2 > .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1 0");
}

TEST(interpret, Incorrect_Work_More_Zero_Number) {
    std::string str = ">";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_More_One_Number) {
    std::string str = "1 > .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Correct_Work_Less) {
    std::string str = "2 6 < . 6 2 < .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 0 1");
}

TEST(interpret, Incorrect_Work_Less_Zero_Number) {
    std::string str = "<";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Less_One_Number) {
    std::string str = "1 < .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Correct_Work_Equal) {
    std::string str = "2 6 = . 7 7 = .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 0 1");
}

TEST(interpret, Incorrect_Work_Equal_One_Number) {
    std::string str = "=";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(interpret, Incorrect_Work_Equl_One_Number) {
    std::string str = "1 = .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 1");
}

TEST(interpret, Correct_Work_Dup) {
    std::string str = "2 dup . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 2 2");
}

TEST(interpret, Incorrect_Work_Dup) {
    std::string str = "dup 2 dup . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError optional operator: not enough numbers");
}

TEST(interpret, Correct_Work_Drop) {
    std::string str = "2 4 drop .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 2");
}

TEST(interpret, Incorrect_Work_Drop) {
    std::string str = "drop . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError optional operator: not enough numbers");
}

TEST(interpret, Correct_Work_Emit) {
    std::string str = "65 emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " A");
}

TEST(interpret, Incorrect_Work_Emit_No_Number) {
    std::string str = "emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError emit: not enough numbers");
}

TEST(interpret, Incorrect_Work_Emit_Not_Ascii) {
    std::string str = "-2 emit";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError emit: number on stack is out of ASCII range");
}

TEST(interpret, Correct_Work_Swap) {
    std::string str = "2 3 swap . .";
    std::string result = Interpreter::getInstance().interpret(str);
    std::cout<< result<<std::endl;
    EXPECT_EQ(result, " 2 3");
}

TEST(interpret, Incorrect_Work_Swap_One_Number) {
    std::string str = "3 swap . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError swap: not enough numbers");
    str = ".";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 3");
}

TEST(interpret, Incorrect_Work_Swap_No_Numbers) {
    std::string str = "swap . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError swap: not enough numbers");
}

TEST(interpret, Correct_Work_Rot) {
    std::string str = "2 3 4 rot . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 3 2 4");
}

TEST(interpret, Incorrect_Work_Rot_No_Number) {
    std::string str = "3 4 rot . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError rot: not enough numbers");
    str = ". .";
    result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 4 3");
}

TEST(interpret, Incorrect_Work_Rot_No_Numbers) {
    std::string str = "rot . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError rot: not enough numbers");
}


TEST(interpret, Correct_Work_Over) {
    std::string str = "2 3 over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result," 2 3 2");
}

TEST(interpret, Incorrect_Work_Over_No_Numbers) {
    std::string str = "over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError over: not enough numbers");
}

TEST(interpret, Incorrect_Work_Over_One_Number) {
    std::string str = "1 over . . .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError over: not enough numbers");
}

TEST(interpret, Correct_Work_Cr) {
    std::string str = " 23 45 . cr .";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " 45\n 23");
}

TEST(interpret, Correct_Work_PrintString) {
    std::string str = ".\" wef awd\"";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, " wef awd");
}

TEST(interpret, Incorrect_Work_PrintString) {
    std::string str = ".\" wef awd";
    std::string result = Interpreter::getInstance().interpret(str);
    EXPECT_EQ(result, "\nError .\": no \"");
}

TEST(interpret, Incorrect_Work_PrintString_Two_Closing_Brackets) {
    std::string str = ".\" wef awd\"\"";
    std::string result = Interpreter::getInstance().interpret(str);
    std::cout << result<< std::endl;
    EXPECT_EQ(result, " wef awd\nno such command: '\"'");
}

TEST(interpret, Incorrect_Work_Underflow) {
    std::stringstream s1;
    s1 << INT_MIN;

    std::stringstream s2;
    s2 << " " << INT_MAX;

    std::string str = "1";
    std::string result = Interpreter::getInstance().interpret(str);

    str = s1.str();
    result = Interpreter::getInstance().interpret(str);

    str = "- .";
    result = Interpreter::getInstance().interpret(str);

    EXPECT_EQ(result, s2.str());
}

TEST(interpret, Incorrect_Work_Owerflow) {
    std::stringstream s1;
    // CR: https://en.cppreference.com/w/cpp/types/numeric_limits
    s1 << " " << INT_MIN;

    std::stringstream s2;
    s2 << INT_MAX;

    std::string str = "1";
    std::string result = Interpreter::getInstance().interpret(str);

    str = s2.str();
    result = Interpreter::getInstance().interpret(str);

    str = "+ .";
    result = Interpreter::getInstance().interpret(str);

    EXPECT_EQ(result, s1.str());
}
