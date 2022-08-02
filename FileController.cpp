//
// Created by Marco on 30/07/2022.
//

#include "FileController.h"
#include <iostream>
#include <vector>
#include <sstream>


std::string FileController:: parseLine(std::string id, std::string title,std::string completed,std::string description){
    std::string parsedLine;
    parsedLine=id+"|"+title+"|"+completed+"|"+description;
   // std::cout <<parsedLine<<std::endl;

    return parsedLine;
}



std::string FileController:: getNextId(std::vector<TodoItem> vect){

    int lastid = 0;

    for(int i = 0; i<vect.size(); i++)
        {
            if(vect[i].getId()>lastid)
            {
                lastid=vect[i].getId();
            }
        }
    lastid ++;
    return std::to_string(lastid);


}

void FileController::writeToFile( const std::string& dataLine){
    std::fstream myFile;
    myFile.open(fileName,std::ios::app );

    if(dataLine!=""){
        if (myFile.fail()){
            std::cerr <<"Error occurred while opening the file..."<<std::endl;
            exit(1);
        }
        if (myFile.is_open()){
            myFile <<dataLine<<std::endl;
            myFile.close();
        }
    }else{
        std::cerr<<"INPUT COMMAND NOT AVAILABLE. . . try again"<<std::endl;
    }
}


const std::string &FileController::getFileName() const {
    return fileName;
}

void FileController::setFileName(const std::string &fileName) {
    FileController::fileName = fileName;
}

FileController::FileController(const std::string &fileName) : fileName(fileName) {}



std::vector<TodoItem> FileController::readFile() {

    std::fstream myFile;
    myFile.open(fileName,std::ios::in );
    //new
    std::vector<TodoItem> vect;

    if (myFile.fail()){
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        std::string line;
        while(std::getline(myFile,line)){

            //new
            if(line!="") {
                std::stringstream test(line);
                TodoItem objtodo;
                std::string segment;

                std::getline(test, segment, '|');
                objtodo.setId(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setTitle(segment);
                std::getline(test, segment, '|');
                objtodo.setCompleted(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setDescription(segment);

                vect.push_back(objtodo);
            }
        }
        myFile.close();
    }
    return vect;

}


std::vector<TodoItem> FileController::readCompleted() {
    std::fstream myFile;
    myFile.open(fileName,std::ios::in );
    //new
    std::vector<TodoItem> vect;

    if (myFile.fail()){
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        std::string line;
        while(std::getline(myFile,line)){

            //new
            if(line!="") {
                std::stringstream test(line);
                TodoItem objtodo;
                std::string segment;

                std::getline(test, segment, '|');
                objtodo.setId(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setTitle(segment);
                std::getline(test, segment, '|');
                objtodo.setCompleted(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setDescription(segment);
                if (objtodo.isCompleted()) {
                    vect.push_back(objtodo);
                }
            }
        }
        myFile.close();
    }
    return vect;
}

std::vector<TodoItem> FileController::readUncompleted() {
    std::fstream myFile;
    myFile.open(fileName,std::ios::in );
    //new
    std::vector<TodoItem> vect;

    if (myFile.fail()){
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        std::string line;
        while(std::getline(myFile,line)){

            //new
            if(line!="") {
                std::stringstream test(line);
                TodoItem objtodo;
                std::string segment;

                std::getline(test, segment, '|');
                objtodo.setId(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setTitle(segment);
                std::getline(test, segment, '|');
                objtodo.setCompleted(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setDescription(segment);
                if (!objtodo.isCompleted()) {
                    vect.push_back(objtodo);
                }
            }
        }
        myFile.close();
    }
    return vect;
}


void FileController::eraseFileLine( const std::string &eraseLine) {
    std::string line;
    std::ifstream fin;

    fin.open(fileName);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char * p = fileName.c_str();
    remove(p);
    rename("temp.txt", p);
}

TodoItem FileController::findTodoById(std::vector<TodoItem> vect, int id) {
    TodoItem todoItem;
    for(int i = 0; i<vect.size() ;i++){
        if(vect[i].getId()==id){
            todoItem.setId(vect[i].getId());
            todoItem.setDescription(vect[i].getDescription());
            todoItem.setCompleted(vect[i].isCompleted());
            todoItem.setTitle(vect[i].getTitle());
        }
    }


    return todoItem;
}
bool FileController:: is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
std::string FileController::completedStatus(bool completed){
    if(!completed){
        return "No";
    }
    if(completed){
        return "Yes";
    }
}

