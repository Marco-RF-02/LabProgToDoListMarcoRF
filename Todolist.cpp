//
// Created by Marco on 10/08/2022.
//

#include "Todolist.h"
#include <iostream>

Todolist::Todolist(const std::list<TodoItem> &todoitemsList) : todoitemsList(todoitemsList) {}

std::string Todolist::completedStatus(bool completed){ // this method is used just for graphical purpose
    std::string compStat="not found";
    if(!completed){
        compStat="No"; // show "No" if todoitem is not completed yet
    }
    if(completed){
        compStat="Yes";// show "Yes" if todoitem is completed
    }
    return compStat;
}

void Todolist::printTodoItemList() {
    int c=0;
    for(const auto& itr : todoitemsList){
        std::cout<<c<<" - "<<itr.getTitle()<<std::endl;
        std::cout<<"Completed: "<<completedStatus(itr.isCompleted())<<std::endl;
        std::cout<<itr.getDescription()<<std::endl;
        std::cout<<itr.getDate().getDay()<<" "<<itr.getDate().getMonth()<<" "<<itr.getDate().getYear()<<std::endl;
        std::cout<<itr.getCategory()<<std::endl;

        std::cout<<"---------------------"<<std::endl;
        c++;
    }

}



const std::list<TodoItem> &Todolist::getTodoitemsList() const {
    return todoitemsList;
}

void Todolist::setTodoitemsList(const std::list<TodoItem> &todoitemsList) {
    Todolist::todoitemsList = todoitemsList;
}

TodoItem Todolist::getTodoToDelete(int num) {
    int c=0;
    for(const auto& itr : todoitemsList){
        if(c==num){
            TodoItem todo(itr.getTitle(),itr.isCompleted(),itr.getDescription(),itr.getDate(),itr.getCategory());
            return todo;
        }
        c++;
    }
    return TodoItem();
}


