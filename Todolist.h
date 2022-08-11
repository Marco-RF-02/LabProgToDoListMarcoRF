//
// Created by Marco on 10/08/2022.
//

#ifndef LABPROGTODOLISTMARCORF_TODOLIST_H
#define LABPROGTODOLISTMARCORF_TODOLIST_H

#include <memory>
#include <list>
#include "TodoItem.h"
#include "FileController.h"

class Todolist {

public:
    std::string completedStatus(bool completed);
    explicit Todolist(const std::list<TodoItem> &todoitemsList);
    TodoItem getTodoToDelete(int num);
    void printTodoItemList();
    bool findByParsedLine(const std::string& parsedline,const std::string& opparsedline,FileController fileController);
    int countCompleted();
    int countNotCompleted();
    const std::list<TodoItem> &getTodoitemsList() const;

    Todolist() = default;

    void setTodoitemsList(const std::list<TodoItem> &todoitemsList);

private:
    std::list<TodoItem> todoitemsList;

};


#endif //LABPROGTODOLISTMARCORF_TODOLIST_H
