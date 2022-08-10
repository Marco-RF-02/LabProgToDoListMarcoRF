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
#include <list>



class FileController {
public:

    explicit FileController(const std::string &fileName);

    void writeToFile( const std::string &dataLine);

    std::list<std::string> categoryList();

    std::list<TodoItem> readFile();


    bool eraseFileLine(const std::string& eraseLine);


    std::string parseLine(const std::string& title,const std::string& completed,const std::string& description, std:: string date, std::string category);
    std::string parseDate(int day,int month, int year);
    bool isDigits(const std::string &str);
    bool changeCompletedStatus(const std::string& parsedLine,const std::string& newparsedline);

private:
     std::string fileName;

};


#endif //LABPROGTODOLISTMARCORF_FILECONTROLLER_H
