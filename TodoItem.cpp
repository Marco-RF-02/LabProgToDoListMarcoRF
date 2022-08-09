//
// Created by Marco on 28/07/2022.
//

#include "TodoItem.h"


//TodoItem::TodoItem( std::string t, std::string descr,bool c): title(t),completed(c),description(descr) {}


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

const Date &TodoItem::getDate() const {
    return date;
}

void TodoItem::setDate(const Date &date) {
    TodoItem::date = date;
}

const std::string &TodoItem::getCategory() const {
    return category;
}

void TodoItem::setCategory(const std::string &category) {
    TodoItem::category = category;
}

TodoItem::TodoItem(const std::string &title, bool completed, const std::string &description, const Date &date,
                   const std::string &category) : title(title), completed(completed), description(description),
                                                  date(date), category(category) {}
