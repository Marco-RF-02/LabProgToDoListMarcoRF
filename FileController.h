//
// Created by Marco on 30/07/2022.
//

#ifndef LABPROGTODOLISTMARCORF_FILECONTROLLER_H
#define LABPROGTODOLISTMARCORF_FILECONTROLLER_H

#include<string>
#include"TodoItem.h"
#include <fstream>
#include<memory>
#include <vector>


class FileController {
public:

    explicit FileController(const std::string &fileName);

    void writeToFile( const std::string &dataLine);
    std::vector<TodoItem> readFile();
    std::vector<TodoItem> readCompleted();
    std::vector<TodoItem> readUncompleted();

    void eraseFileLine(const std::string& eraseLine);

    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);
    std::string parseLine(std::string id, std::string title,std::string completed,std::string description);
    std::string getNextId(std::vector<TodoItem> vect);
    TodoItem findTodoById(std::vector<TodoItem> vect, int id);
    bool is_digits(const std::string &str);
private:
     std::string fileName;

};


#endif //LABPROGTODOLISTMARCORF_FILECONTROLLER_H
