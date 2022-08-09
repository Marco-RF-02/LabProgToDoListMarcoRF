//
// Created by Marco on 28/07/2022.
//

#ifndef LABPROGTODOLISTMARCORF_TODOITEM_H
#define LABPROGTODOLISTMARCORF_TODOITEM_H

#include<string>
#include "Date.h"

class TodoItem {
public:
  //  TodoItem(std::string t, std::string descr, bool p = false);
    ~TodoItem() = default;

    TodoItem(const std::string &title, bool completed, const std::string &description, const Date &date,
             const std::string &category);

    TodoItem() = default;

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    bool isCompleted() const;

    void setCompleted(bool completed);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const Date &getDate() const;

    void setDate(const Date &date);

    const std::string &getCategory() const;

    void setCategory(const std::string &category);

private:
    std::string title;
    bool completed;
    std::string description;
    Date date;
    std::string category;


};

#endif //LABPROGTODOLISTMARCORF_TODOITEM_H
