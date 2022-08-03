#include <iostream>
#include<string>
#include "TodoItem.h"
#include "FileController.h"
#include<algorithm>


std::string removeSpaces(std::string input) // this func is used to remove spaces from string input
{
    input.erase(std::remove(input.begin(),input.end(),' '),input.end()); // remove spaces
    input.erase(std::remove(input.begin(),input.end(),'\t'),input.end());// remove tabs
    return input;
}

void printTodoList(std::vector<TodoItem> vect, FileController fileController){  // print todoitemvector

    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}

std::string getInputText() { // this is used to control various wrong inputs from user
    std::string input;
    while(input.empty() || input[0]==' '||input[0]=='\t' || input.find_first_not_of(' ')==std::string::npos || input.find_first_not_of('\t')==std::string::npos) {
        getline(std::cin, input);
    }
    return input;
}

void addTodoItem(FileController fileController){ // add new todoitem
    std::string parsedline;
    std::string title;
    std::string description;

    //Ask input details

    std::cout<<"Insert new todo "<<std::endl;

    std::cout<<"Insert title: "<<std::endl;
    title=getInputText();

    std::cout<<"Insert description: "<<std::endl;
    description=getInputText();

    //parsing line before writing into the text file
    parsedline = fileController.parseLine(fileController.getNextId(fileController.readFile()),title, std::to_string(0),description);

    //adding to the txtfile
    fileController.writeToFile(parsedline);

    std::cout<<"---------------------"<<std::endl;
}

void deleteTodo(FileController fileController){
    std::string input;
    // print the todolist in order to decide what to delete
    std::cout << "What do you want to delete ?" << std::endl;
    std::vector<TodoItem> vect;
    vect = fileController.readFile();
    printTodoList(vect, fileController);



    // ask for the id
    std::cout << "Insert the id of the todo you want to delete: " << std::endl;
    input = getInputText();

    if(fileController.is_digits(input)) {
        //find item to delete
        TodoItem todoItem;
        todoItem = fileController.findTodoById(fileController.readFile(), stoi(input));

        //check if it is found
        if (todoItem.getDescription() == "" && todoItem.getTitle() == "" && todoItem.isCompleted() == 0) {
            std::cout << "todo not found" << std::endl;
        } else {

            //delete
            fileController.eraseFileLine(
                    fileController.parseLine(std::to_string(todoItem.getId()), todoItem.getTitle(),
                                             std::to_string(todoItem.isCompleted()),
                                             todoItem.getDescription()));
        }
    }else{
        std::cerr << "input not valid. . ." << std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}

void changeCompletedStatus(FileController fileController){
    std::string input;
    std::cout << "Which todo needs to change its (completed) status?" << std::endl;
    std::vector<TodoItem> vect;
    vect = fileController.readFile();
    printTodoList(vect,fileController);

    // ask for the id
    std::cout << "Insert the id of the todo you want to change the (completed) status of: " << std::endl;
    input = getInputText();
    input = removeSpaces(input);

    if(fileController.is_digits(input)) {
        //find item to modify its status
        TodoItem todoItem;
        todoItem = fileController.findTodoById(fileController.readFile(), stoi(input));

        //check if it is found
        if (todoItem.getDescription() == "" && todoItem.getTitle() == "" && todoItem.isCompleted() == 0) {
            std::cout << "todo not found" << std::endl;
        } else {
            // a new todoitem is added with same specs of the one which needs to be changed,
            // but with different completed status

            std::string parsedline;
            std::string inpCompStatus;
            std::cout << "insert completed status " << std:: endl;
            std::cout << "[0] Todo not Completed" << std:: endl;
            std::cout << "[1] Todo Completed" << std:: endl;
            inpCompStatus = getInputText();
            inpCompStatus = removeSpaces(inpCompStatus);

            if(fileController.is_digits(inpCompStatus)) {
                if(inpCompStatus=="0"||inpCompStatus=="1") {

                    //delete the old todoitem
                    fileController.eraseFileLine(
                            fileController.parseLine(std::to_string(todoItem.getId()), todoItem.getTitle(),
                                                     std::to_string(todoItem.isCompleted()),
                                                     todoItem.getDescription()));

                    parsedline = fileController.parseLine(std::to_string(todoItem.getId()),
                                                          todoItem.getTitle(), inpCompStatus, todoItem.getDescription());
                    fileController.writeToFile(parsedline);

                }else{
                    std::cerr << "input not valid. . ." << std::endl;
                }
            }else{
                std::cerr << "input not valid. . ." << std::endl;
            }
        }
    }else{
        std::cerr << "input not valid. . ." << std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}

void showCompleted(FileController fileController){ //show completed todoitems
    std::vector<TodoItem> vect;
    vect = fileController.readCompleted();
    printTodoList(vect,fileController);

}

void showNotCompleted(FileController fileController){ // show uncompleted todoitems
    std::vector<TodoItem> vect;
    vect = fileController.readUncompleted();
    printTodoList(vect,fileController);

}
void showAll(FileController fileController){ // show all todoitems
    std::vector<TodoItem> vect;
    vect = fileController.readFile();
    printTodoList(vect,fileController);


}


int main() {

    std::string command;
    std::string input;
    std::string file="TodoTextFile.txt";
    FileController fileController(file);
    bool menu = true;

    while(menu)
    {


        //menu
        std::cout<<"This is your todo List menu"<<std::endl;
        std::cout<<"What would you like to do?"<<std::endl;
        std::cout<<"Insert the number of the action:"<<std::endl;
        std::cout<<"[0] Quit"<<std::endl;
        std::cout<<"[1] Add todo"<<std::endl;
        std::cout<<"[2] Delete todo"<<std::endl;
        std::cout<<"[3] Change completed status"<<std::endl;
        std::cout<<"[4] Show completed todo"<<std::endl;
        std::cout<<"[5] Show uncompleted todo"<<std::endl;
        std::cout<<"[6] Show all "<<std::endl;

        try { // there are already multiple controls but this try-catch block gives us more safety
            command = getInputText();
            command = removeSpaces(command);
        }catch (std::exception& e){
            std::cerr << "Input error. . . \n";
        }

        if(fileController.is_digits(command)) {
            try { // try exceptions consequently to user input
                int c = std::stoi(command);

                switch (c) {
                    case 0:
                        std::cout << "exit the program" << std::endl;
                        menu = false;
                        break;
                    case 1:
                        addTodoItem(fileController);
                        break;
                    case 2:
                        deleteTodo(fileController);
                        break;
                    case 3:
                        changeCompletedStatus(fileController);
                        break;
                    case 4:
                        showCompleted(fileController);
                        break;
                    case 5:
                        showNotCompleted(fileController);
                        break;
                    case 6:
                        showAll(fileController);
                        break;
                    default:
                        std::cerr << "Bad choice! Please try again: \n"; // if wrong user input, print error
                        break;
                }

            }catch (std::out_of_range& e){ // catch out of range
                std::cerr << "Input too long. Try Again\n";
            } catch (std::exception& e) { // catch various exceptions
                std::cerr << "Unknown error. . . try Again\n";
            }
        }else{
            std::cerr << "Input not valid. . . \n";
        }
    }
    return 0;
}