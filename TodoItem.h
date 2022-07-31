//
// Created by Marco on 28/07/2022.
//

#ifndef LABPROGTODOLISTMARCORF_TODOITEM_H
#define LABPROGTODOLISTMARCORF_TODOITEM_H

#include<string>

class TodoItem {
public:
    TodoItem(int id, std::string t, std::string descr, bool p = false);
    ~TodoItem() = default;

    TodoItem();

    int getId() const;

    void setId(int id);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    bool isCompleted() const;

    void setCompleted(bool completed);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

private:
    int id;
    std::string title;
    bool completed;
    std::string description;


};


#endif //LABPROGTODOLISTMARCORF_TODOITEM_H
