//
// Created by Marco on 30/07/2022.
//

#ifndef LABPROGTODOLISTMARCORF_FILECONTROLLER_H
#define LABPROGTODOLISTMARCORF_FILECONTROLLER_H

#include<string>
#include"TodoItem.h"
#include <fstream>

class FileController {
public:

    FileController(const std::string &fileName);

    void writeToFile( const std::string &dataLine);

    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);


private:
     std::string fileName;

};


#endif //LABPROGTODOLISTMARCORF_FILECONTROLLER_H
