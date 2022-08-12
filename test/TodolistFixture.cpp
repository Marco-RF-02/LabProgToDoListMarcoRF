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
            date.setDay(1 + i);
            date.setMonth(1 + i);
            date.setYear(2025 + i);
            todo.setTitle("title"+ std::to_string(i));
            todo.setCompleted(false);
            todo.setDescription("description"+ std::to_string(i));
            todo.setDate(date);
            todo.setCategory("category"+ std::to_string(i));


            listTodoItems.push_back(todo);
        }
        todolist.setTodoitemsList(listTodoItems);
        todo1.setTitle("title0");
        date.setDay(1);
        date.setMonth(1);
        date.setYear(2025);
        todo1.setDate(date);
        todo1.setCompleted(false);
        todo1.setDescription("description0");
        todo1.setCategory("category0");


        todo2.setTitle("titleAdd");
        date.setDay(1);
        date.setMonth(1);
        date.setYear(2025);
        todo2.setDate(date);
        todo2.setCompleted(false);
        todo2.setDescription("descriptionAdd");
        todo2.setCategory("categoryAdd");
    }

    Todolist todolist;
    TodoItem todo1;
    TodoItem todo2;


};

TEST_F(TodolistSuite, countNotCompletedTest) {
    setup();
    ASSERT_EQ(5,todolist.countNotCompleted());
}
TEST_F(TodolistSuite, countCompletedTest) {
    setup();
    ASSERT_EQ(0,todolist.countCompleted());
}

TEST_F(TodolistSuite, deleteFromListTest) {
    setup();
    todolist.deleteFromList(todo1);
    ASSERT_FALSE(todolist.findTodoItem(todo1));

}

TEST_F(TodolistSuite, addToListTest) {
    setup();
    ASSERT_FALSE(todolist.findTodoItem(todo2));
    todolist.addToList(todo2);
    ASSERT_TRUE(todolist.findTodoItem(todo2));

}

TEST_F(TodolistSuite, findTodoItemTest) {
    setup();
ASSERT_TRUE(todolist.findTodoItem(todo1));
    ASSERT_FALSE(todolist.findTodoItem(todo2));
}

