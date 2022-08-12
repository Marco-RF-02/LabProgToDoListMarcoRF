//
// Created by Marco on 28/07/2022.
//

#include "TodoItem.h"
#include <sstream>


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

TodoItem TodoItem::deparseObjTodoItem(const std::string& line) {

    std::stringstream test(line);
    std::string segment;
    TodoItem objtodo;
    Date objdate;

    // in order to read properly from file,
    // we need to decide a specific criteria
    std::getline(test, segment, '|');
    objtodo.setTitle(segment);
    std::getline(test, segment, '|');
    objtodo.setCompleted(stoi(segment));
    std::getline(test, segment, '|');
    objtodo.setDescription(segment);
    std::getline(test, segment, '|');
    objtodo.setDate(objdate.deparseDate(segment));
    std::getline(test, segment, '|');
    objtodo.setCategory(segment);

    return objtodo;
}

bool TodoItem::operator==(const TodoItem &rhs) const {
    return completed == rhs.completed &&
           title == rhs.title &&
           completed == rhs.completed &&
           description == rhs.description &&
           date == rhs.date &&
           category == rhs.category;
}

bool TodoItem::operator!=(const TodoItem &rhs) const {
    return !(rhs == *this);
}

bool TodoItem::operator<(const TodoItem &rhs) const {
    if (title < rhs.title)
        return true;
    if (rhs.title < title)
        return false;
    if (completed < rhs.completed)
        return true;
    if (rhs.completed < completed)
        return false;
    if (description < rhs.description)
        return true;
    if (rhs.description < description)
        return false;
    if (date < rhs.date)
        return true;
    if (rhs.date < date)
        return false;
    return category < rhs.category;
}

bool TodoItem::operator>(const TodoItem &rhs) const {
    return rhs < *this;
}

bool TodoItem::operator<=(const TodoItem &rhs) const {
    return !(rhs < *this);
}

bool TodoItem::operator>=(const TodoItem &rhs) const {
    return !(*this < rhs);
}
