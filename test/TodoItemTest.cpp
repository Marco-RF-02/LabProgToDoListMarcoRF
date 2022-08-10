//
// Created by Marco on 04/08/2022.
//

#include "gtest/gtest.h"
#include"../TodoItem.h"

TEST(TodoItem, DefaultConstructor) {
    TodoItem t;
    ASSERT_FALSE(t.isCompleted());
}


TEST(TodoItem, getTitleTest) {
    TodoItem t;
    t.setTitle("test");
    ASSERT_EQ("test",t.getTitle());
}
TEST(TodoItem, getDescriptionTest) {
    TodoItem t;
    t.setDescription("desc");
    ASSERT_EQ("desc",t.getDescription());
}
TEST(TodoItem, isCompletedTest) {
    TodoItem t;
    t.setCompleted(true);
    ASSERT_EQ(1,t.isCompleted());
}

TEST(TodoItem, deparseObjTodoItemTest) {
    TodoItem t;
    t=t.deparseObjTodoItem("t|1|d|1^1^1111|1");
    ASSERT_EQ("t",t.getTitle());
    ASSERT_EQ("d",t.getDescription());
    ASSERT_EQ(1,t.isCompleted());
    ASSERT_EQ(1,t.getDate().getDay());
    ASSERT_EQ(1,t.getDate().getMonth());
    ASSERT_EQ(1111,t.getDate().getYear());
    ASSERT_EQ("1",t.getCategory());
}

