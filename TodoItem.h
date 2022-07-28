//
// Created by Marco on 28/07/2022.
//

#ifndef LABPROGTODOLISTMARCORF_TODOITEM_H
#define LABPROGTODOLISTMARCORF_TODOITEM_H

#include<string>

class TodoItem {
public:
    TodoItem(): id(0), completed(false){};
    ~TodoItem() = default;

private:
    int id;
    std::string title;
    bool completed;
    std::string description;

};


#endif //LABPROGTODOLISTMARCORF_TODOITEM_H
