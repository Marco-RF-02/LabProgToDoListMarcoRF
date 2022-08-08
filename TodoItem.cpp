//
// Created by Marco on 28/07/2022.
//

#include "TodoItem.h"


TodoItem::TodoItem(int id, std::string t, std::string descr,bool c): id(id), title(t),completed(c),description(descr) {}


int TodoItem::getId() const {
    return id;
}

void TodoItem::setId(int id) {
    TodoItem::id = id;
}

const std::string &TodoItem::getTitle() const {
    return title;
}

void TodoItem::setTitle(const std::string &title) {
    TodoItem::title = title;
}

bool TodoItem::isCompleted() const {
    return completed;
}

void TodoItem::setCompleted(bool completed) {
    TodoItem::completed = completed;
}

const std::string &TodoItem::getDescription() const {
    return description;
}

void TodoItem::setDescription(const std::string &description) {
    TodoItem::description = description;
}
