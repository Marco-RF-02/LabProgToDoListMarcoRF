//
// Created by Marco on 04/08/2022.
//
#include "gtest/gtest.h"
#include "../FileController.h"

TEST(FileController, parseLineTest) {
    FileController fileController("test");
    ASSERT_EQ("id|title|comp|desc",fileController.parseLine("id","title","comp","desc"));
    ASSERT_NE("idtitlecompdesc",fileController.parseLine("id","title","comp","desc"));
}

TEST(FileController, is_digitsTest) {

FileController fileController("test");
    ASSERT_EQ(true,fileController.isDigits("123"));
    ASSERT_NE(true,fileController.isDigits("abc"));

}

TEST(FileController, completedStatusTest) {
    FileController fileController("test");
    ASSERT_EQ("Yes",fileController.completedStatus(1));
    ASSERT_NE("Yes",fileController.completedStatus(0));
    ASSERT_EQ("No",fileController.completedStatus(0));
    ASSERT_NE("No",fileController.completedStatus(1));

}
