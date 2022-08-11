//
// Created by Marco on 10/08/2022.
//

#include "gtest/gtest.h"
#include"../Todolist.h"

TEST(Todolist, completedStatusTest) {
    Todolist todolist;
    ASSERT_EQ("No",todolist.completedStatus(0));
    ASSERT_EQ("Yes",todolist.completedStatus(1));
}
