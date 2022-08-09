//
// Created by Marco on 04/08/2022.
//
#include "gtest/gtest.h"
#include "../FileController.h"

class FileControllerSuite : public ::testing::Test {

protected:

   virtual void setup(){
        for(int i = 0; i< 5; i++){
          //  obj.setId(i);
            obj.setTitle("title"+ std::to_string(i));
            obj.setDescription("description"+ std::to_string(i));
            obj.setCompleted(i%2);
            vect.push_back(obj);
        }
    }
    std::vector<TodoItem> vect;
    TodoItem obj;

};




