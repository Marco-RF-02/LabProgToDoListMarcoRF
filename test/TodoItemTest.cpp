//
// Created by Marco on 04/08/2022.
//

#include "gtest/gtest.h"
#include"../TodoItem.h"

TEST(TodoItem, DefaultConstructor) {
    TodoItem t;
    ASSERT_FALSE(t.isCompleted());
}

TEST(TodoItem, getIdTest) {
    TodoItem t;
    t.setId(1);
    ASSERT_EQ(1,t.getId());
    ASSERT_NE(2,t.getId());
}
TEST(TodoItem, getTitleTest) {
    TodoItem t;
    t.setTitle("test");
    ASSERT_EQ("test",t.getTitle());
    ASSERT_NE("t",t.getTitle());
}
TEST(TodoItem, getDescriptionTest) {
    TodoItem t;
    t.setDescription("desc");
    ASSERT_EQ("desc",t.getDescription());
    ASSERT_NE("d",t.getDescription());
}
TEST(TodoItem, isCompletedTest) {
    TodoItem t;
    t.setCompleted(1);
    ASSERT_EQ(1,t.isCompleted());
    ASSERT_NE(0,t.isCompleted());
}

