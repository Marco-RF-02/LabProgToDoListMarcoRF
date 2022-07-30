//
// Created by Marco on 30/07/2022.
//

#include "FileController.h"
#include <iostream>




void FileController::writeToFile( const std::string& dataLine){
    std::fstream myFile;
    myFile.open(fileName,std::ios::app );

    if (myFile.fail()){
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        myFile <<dataLine<<std::endl;
        myFile.close();
    }
}


const std::string &FileController::getFileName() const {
    return fileName;
}

void FileController::setFileName(const std::string &fileName) {
    FileController::fileName = fileName;
}

FileController::FileController(const std::string &fileName) : fileName(fileName) {}

void FileController::readFile() {
    std::fstream myFile;
    myFile.open(fileName,std::ios::in );

    if (myFile.fail()){
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        std::string line;
        while(std::getline(myFile,line)){
            std::cout <<line<<std::endl;
        }
        myFile.close();
    }
}


