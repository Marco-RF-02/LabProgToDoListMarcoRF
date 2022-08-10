//
// Created by Marco on 30/07/2022.
//

#include "FileController.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "Todolist.h"
#include <fstream>

FileController::FileController(const std::string &fileName) : fileName(fileName) {}

std::string FileController:: parseDate(int day, int month,int year){
    std::string parsedLine;
    parsedLine= std::to_string(day)+"^"+ std::to_string(month)+"^"+ std::to_string(year); // "^" is the separator
    return parsedLine; // this method return a parsed line for the date
}

std::string FileController:: parseLine(const std::string& title, const std::string& completed, const std::string& description, std:: string date, std:: string category){
    std::string parsedLine;
    parsedLine=title+"|"+completed+"|"+description+"|"+date+"|"+category; // "|" is the separator
  //  std::cout<<parsedLine;
    return parsedLine; // this method return a parsed line
}



/*
std::string FileController:: getNextId(const std::vector<TodoItem>& vect){ // get new id by making it impossible to have 2 identical id

    int lastid = 0;

    for(auto & i : vect)
        {
            if(i.getId()>lastid)
            {
                lastid=i.getId();
            }
        }
    lastid ++;
    return std::to_string(lastid); // new id is incremented by 1 compared to last id registered in the vector
}
*/
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


/*
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
            if(!line.empty()) {
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
*/


/*
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
            if(!line.empty()) {
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
*/

/*

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
*/

/*
TodoItem FileController::findTodoById(const std::vector<TodoItem>& vect, int id) { // find todoitem by using its id
    TodoItem todoItem;
    for(auto & i : vect){
        if(i.getId()==id){
            todoItem.setId(i.getId());
            todoItem.setDescription(i.getDescription());
            todoItem.setCompleted(i.isCompleted());
            todoItem.setTitle(i.getTitle());
        }
    }
    return todoItem;
}
*/

bool FileController:: isDigits(const std::string &str) // this method controls if user is writing only numbers
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


std::list<std::string> FileController::categoryList() {

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

    std::string inbuf;
    std::fstream input_file("TodoTextFile.txt", std::ios::in);
    std::ofstream output_file("result.txt");

    while (!input_file.eof())
    {
        getline(input_file, inbuf);

        int spot = inbuf.find(search_string);
        if(spot >= 0)
        {
            std::string tmpstring = inbuf.substr(0,spot);
            tmpstring += replace_string;
            tmpstring += inbuf.substr(spot+search_string.length(), inbuf.length());
            inbuf = tmpstring;
            done=true;
        }

        output_file << inbuf << std::endl;
    }

    output_file.close();
    input_file.close();

    const char * p = fileName.c_str();
    remove(p);
    rename("result.txt", p);

    return done;
}

