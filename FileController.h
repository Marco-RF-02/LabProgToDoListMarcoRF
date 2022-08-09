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

    //use list instead of vect
 //   std::vector<TodoItem> readFile();
 //   std::vector<TodoItem> readCompleted();
  //  std::vector<TodoItem> readUncompleted();

    void eraseFileLine(const std::string& eraseLine);

    //change removing id and adding new attributes
    std::string parseLine(const std::string& title,const std::string& completed,const std::string& description, std:: string date, std::string category);
    std::string parseDate(int day,int month, int year);
    //remove id
 //   std::string getNextId(const std::vector<TodoItem>& vect);
  //  TodoItem findTodoById(const std::vector<TodoItem>& vect, int id);
   // bool isDigits(const std::string &str);
    std::string completedStatus(bool input);
private:
     std::string fileName;

};


#endif //LABPROGTODOLISTMARCORF_FILECONTROLLER_H
