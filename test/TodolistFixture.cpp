//
// Created by Marco on 10/08/2022.
//

#include "gtest/gtest.h"
#include"../Todolist.h"

class TodolistSuite : public ::testing::Test {

protected:
    virtual void setup(){
        std::list <TodoItem> listTodoItems;
        Date date;
        TodoItem todo;

        for(int i = 0; i< 5; i++){
            date.setDay(1+i);
            date.setMonth(1+i);
            date.setYear(2025+i);
            todo.setTitle("title"+ std::to_string(i));
            todo.setCompleted(false);
            todo.setDescription("description"+ std::to_string(i));
            todo.setDate(date);
            todo.setCategory("category"+ std::to_string(i));


            listTodoItems.push_back(todo);
        }
        todolist.setTodoitemsList(listTodoItems);
    }

    Todolist todolist;

};

TEST_F(TodolistSuite, countNotCompletedTest) {
    setup();
    ASSERT_EQ(5,todolist.countNotCompleted());
}
TEST_F(TodolistSuite, countCompletedTest) {
    setup();
    ASSERT_EQ(0,todolist.countCompleted());
}
