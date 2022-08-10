//
// Created by Marco on 04/08/2022.
//
#include "gtest/gtest.h"
#include "../FileController.h"

TEST(FileController, parseLineTest) {
    FileController fileController("test");
    ASSERT_EQ("title|comp|desc|1^1^1111|category",fileController.parseLine("title","comp","desc","1^1^1111","category"));
}
/*
TEST(FileController, is_digitsTest) {

FileController fileController("test");
    ASSERT_EQ(true,fileController.isDigits("123"));

}

TEST(FileController, completedStatusTest) {
    FileController fileController("test");
    ASSERT_EQ("Yes",fileController.completedStatus(1));
    ASSERT_EQ("No",fileController.completedStatus(0));

}
 */

TEST(FileController, parseDateTest) {
    FileController fileController("test");
    ASSERT_EQ("1^1^111",fileController.parseDate(1,1,111));


}
