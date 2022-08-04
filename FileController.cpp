//
// Created by Marco on 30/07/2022.
//

#include "FileController.h"
#include <iostream>
#include <vector>
#include <sstream>


std::string FileController:: parseLine(const std::string& id, const std::string& title, const std::string& completed, const std::string& description){
    std::string parsedLine;
    parsedLine=id+"|"+title+"|"+completed+"|"+description; // "|" is the separator
    return parsedLine; // this method return a parsed line
}



std::string FileController:: getNextId(std::vector<TodoItem> vect){ // get new id by making it impossible to have 2 identical id

    int lastid = 0;

    for(int i = 0; i<vect.size(); i++)
        {
            if(vect[i].getId()>lastid)
            {
                lastid=vect[i].getId();
            }
        }
    lastid ++;
    return std::to_string(lastid); // new id is incremented by 1 compared to last id registered in the vector
}

void FileController::writeToFile( const std::string& dataLine){ // this method is used to write to file
    std::fstream myFile;
    myFile.open(fileName,std::ios::app ); // file gets opened with append mode

    if(dataLine!=""){
        if (myFile.fail()){ // control over file opening success
            std::cerr <<"Error occurred while opening the file..."<<std::endl;
            exit(1);
        }
        if (myFile.is_open()){
            myFile <<dataLine<<std::endl; // writes line into file
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


std::vector<TodoItem> FileController::readFile() { // method used to read from file and put the various todoitems into a vector

    std::fstream myFile;
    myFile.open(fileName,std::ios::in ); // file gets opened in input mode
    std::vector<TodoItem> vect;

    if (myFile.fail()){ // control over the file opening success
        std::cerr <<"Error occurred while opening the file..."<<std::endl;
        exit(1);
    }
    if (myFile.is_open()){
        std::string line;
        while(std::getline(myFile,line)){

            if(line!="") {
                std::stringstream test(line);
                TodoItem objtodo;
                std::string segment;

                // in order to read properly from file,
                // we need to decide a specific criteria
                std::getline(test, segment, '|');
                objtodo.setId(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setTitle(segment);
                std::getline(test, segment, '|');
                objtodo.setCompleted(stoi(segment));
                std::getline(test, segment, '|');
                objtodo.setDescription(segment);

                vect.push_back(objtodo); // after receiving all info, the object is pushed into the vector
            }
        }
        myFile.close(); // close the file
    }
    return vect;

}


std::vector<TodoItem> FileController::readCompleted() { // read completed todoitems from file
    std::fstream myFile;
    myFile.open(fileName,std::ios::in );

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

std::vector<TodoItem> FileController::readUncompleted() { // read only uncompleted todoitems from file
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


void FileController::eraseFileLine( const std::string &eraseLine) { // method used to erase a chosen line from a text file
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

TodoItem FileController::findTodoById(std::vector<TodoItem> vect, int id) { // find todoitem by using its id
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
bool FileController:: is_digits(const std::string &str) // this method controls if user is writing only numbers
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

std::string FileController::completedStatus(bool completed){ // this method is used just for graphical purpose
    std::string compStat="not found";
    if(!completed){
        compStat="No"; // show "No" if todoitem is not completed yet
    }
    if(completed){
        compStat="Yes";// show "Yes" if todoitem is completed
    }
    return compStat;
}

