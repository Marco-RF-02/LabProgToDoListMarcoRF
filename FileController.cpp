//
// Created by Marco on 30/07/2022.
//

#include "FileController.h"
#include <iostream>
#include "Todolist.h"

FileController::FileController(const std::string &fileName) : fileName(fileName) {}

std::string FileController:: parseDate(int day, int month,int year){
    std::string parsedLine;
    parsedLine= std::to_string(day)+"^"+ std::to_string(month)+"^"+ std::to_string(year); // "^" is the separator
    return parsedLine; // this method return a parsed line for the date
}

std::string FileController:: parseLine(const std::string& title, const std::string& completed, const std::string& description, std:: string date, std:: string category){
    std::string parsedLine;
    parsedLine=title+"|"+completed+"|"+description+"|"+date+"|"+category; // "|" is the separator
    return parsedLine; // this method return a parsed line
}

void FileController::writeToFile( const std::string& dataLine){ // this method is used to write to file
    std::fstream myFile;
    myFile.open(fileName,std::ios::app ); // file gets opened with append mode

    if(!dataLine.empty()){
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


std::list<TodoItem> FileController::readFile() { // method used to read from file and put the various todoitems into a vector

         std::fstream myFile;
         myFile.open(fileName,std::ios::in ); // file gets opened in input mode
         std::list<TodoItem> todoList;
         Date date;

         if (myFile.fail()){ // control over the file opening success
             std::cerr <<"Error occurred while opening the file..."<<std::endl;
             exit(1);
         }
         if (myFile.is_open()){
             std::string line;
             while(std::getline(myFile,line)){

                 if(!line.empty()) {
                     TodoItem objtodo;
                     objtodo = objtodo.deparseObjTodoItem(line);

                     todoList.push_back(objtodo); // after receiving all info, the object is pushed into the list
                 }
             }
             myFile.close(); // close the file
         }
         return todoList;
}

bool FileController:: isDigits(const std::string &str) // this method controls if user is writing only numbers
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

std::list<std::string> FileController::categoryList() { // creates a list of different categories

    std::list<std::string> categoryList;
    Todolist todolist (readFile());

    bool f ;
    for(const auto& itr : todolist.getTodoitemsList()){
        f=true;
            for(const auto& i : categoryList) {
                if(itr.getCategory() == i) {
                    f = false;
                }
            }
        if(f){
            categoryList.push_back(itr.getCategory());
        }

    }

    return categoryList;
}


bool FileController::eraseFileLine( const std::string &eraseLine) { // method used to erase a chosen line from a text file
    bool done= false;
    std::string line;
    std::ifstream fin;

    fin.open(fileName);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != eraseLine) {
            temp << line << std::endl;

        }else{
            done=true;
        }
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char * p = fileName.c_str();
    remove(p);
    rename("temp.txt", p);

    if(!done){
        std::cerr << "Not Found. . . \n";
    }
    return done;
}


bool FileController::changeCompletedStatus(const std::string& search_string, const std::string& replace_string) {
  bool done= false;

    // initializing variables
    std::string inbuf;
    std::fstream input_file(fileName, std::ios::in);
    std::ofstream output_file("result.txt");

    // while the end of the file is not reached
    while (!input_file.eof())
    {
        // read line from the file inbuf
        getline(input_file, inbuf);

        // find spot of the searched string
        int spot = inbuf.find(search_string);
        if(spot >= 0)
        {
            // replace in the same spot the new string
            std::string tmpstring = inbuf.substr(0,spot);
            tmpstring += replace_string;
            tmpstring += inbuf.substr(spot+search_string.length(), inbuf.length());
            inbuf = tmpstring;
            done=true;
        }

        output_file << inbuf << std::endl;
    }

    // closing the files
    output_file.close();
    input_file.close();

    // rename the temp file and delete the old file
    const char * p = fileName.c_str();
    remove(p);
    rename("result.txt", p);

    return done;
}

