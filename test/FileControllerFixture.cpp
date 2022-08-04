//
// Created by Marco on 04/08/2022.
//
#include "gtest/gtest.h"
#include "../FileController.h"

class FileControllerSuite : public ::testing::Test {

protected:

   virtual void setup(){
        for(int i = 0; i< 5; i++){
            obj.setId(i);
            obj.setTitle("title"+ std::to_string(i));
            obj.setDescription("description"+ std::to_string(i));
            obj.setCompleted(i%2);
            vect.push_back(obj);
        }
    }
    std::vector<TodoItem> vect;
    TodoItem obj;

};

TEST_F(FileControllerSuite, getNextIdTest) {
    FileController fileController("test");
    setup();

    ASSERT_EQ("5", (fileController.getNextId(vect)));
}

TEST_F(FileControllerSuite, findTodoByIdTest) {
    FileController fileController("test");
    setup();

    ASSERT_EQ(1 ,(fileController.findTodoById(vect, 1)).getId());
    ASSERT_EQ("title1" ,(fileController.findTodoById(vect, 1)).getTitle());
    ASSERT_EQ( 1,(fileController.findTodoById(vect, 1)).isCompleted());
    ASSERT_EQ("description1" ,(fileController.findTodoById(vect, 1)).getDescription());

    ASSERT_EQ("description3" ,(fileController.findTodoById(vect, 3)).getDescription());
    ASSERT_EQ("description2" ,(fileController.findTodoById(vect, 2)).getDescription());

    ASSERT_NE(1 ,(fileController.findTodoById(vect, 3)).getId());
    ASSERT_NE("test" ,(fileController.findTodoById(vect, 3)).getTitle());
    ASSERT_NE(0 ,(fileController.findTodoById(vect, 3)).isCompleted());
    ASSERT_NE("test" ,(fileController.findTodoById(vect, 3)).getDescription());
}
