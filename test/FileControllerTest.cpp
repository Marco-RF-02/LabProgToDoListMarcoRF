//
// Created by Marco on 04/08/2022.
//
#include "gtest/gtest.h"
#include "../FileController.h"

TEST(FileController, parseLineTest) {
    FileController fileController("test");
    ASSERT_EQ("title|comp|desc|1^1^1111|category",fileController.parseLine("title","comp","desc","1^1^1111","category"));
}

TEST(FileController, parseDateTest) {
    FileController fileController("test");
    ASSERT_EQ("1^1^111",fileController.parseDate(1,1,111));

}


TEST(FileController, isDigitsTest) {

FileController fileController("test");
    ASSERT_EQ(true,fileController.isDigits("123"));

}

TEST(FileController, eraseFileLineTest) {
    FileController fileController("test");
    ASSERT_EQ(false,fileController.eraseFileLine("Line"));
}
