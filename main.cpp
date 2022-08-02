#include <iostream>
#include<string>
#include "TodoItem.h"
#include "FileController.h"
#include <limits>

void addTodoItem(FileController fileController){
    std::string parsedline;
    std::string title;
    std::string description;

    //Ask input details
    std::cin.ignore(1000, '\n');
    std::cout<<"Insert new todo "<<std::endl;

    std::cout<<"Insert title: "<<std::endl;
    while(title.empty() || title.find_first_not_of(' ')==std::string::npos || title.find_first_not_of('\t')==std::string::npos) {
        getline(std::cin, title);
    }

    std::cout<<"Insert description: "<<std::endl;
    while(description.empty() || description.find_first_not_of(' ') == std::string::npos || description.find_first_not_of('\t')==std::string::npos) {
        getline(std::cin, description);
    }

    //parsing line before writing into the text file
    parsedline = fileController.parseLine(fileController.getNextId(fileController.readFile()),title, std::to_string(0),description);

    //adding to the txtfile
    fileController.writeToFile(parsedline);
    title.clear();
    description.clear();

    std::cout<<"---------------------"<<std::endl;
}
void deleteTodo(FileController fileController){
    std::string input;
    // print the todolist in order to decide what to delete
    std::cout << "What do you want to delete ?" << std::endl;
    std::vector<TodoItem> vect;
    vect=fileController.readFile();
    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;



    //Ask for the id
    std::cin.ignore(1000, '\n');
    std::cout << "Insert the id of the todo you want to delete: " << std::endl;
    getline(std::cin, input);

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
    vect=fileController.readFile();
    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;

    //Ask for the id
    std::cin.ignore(1000, '\n');
    std::cout << "Insert the id of the todo you want to change the (completed) status of: " << std::endl;
    getline(std::cin, input);

    if(fileController.is_digits(input)) {
        //find item to modify its status
        TodoItem todoItem;
        todoItem = fileController.findTodoById(fileController.readFile(), stoi(input));

        //check if it is found
        if (todoItem.getDescription() == "" && todoItem.getTitle() == "" && todoItem.isCompleted() == 0) {
            std::cout << "todo not found" << std::endl;
        } else {
            // a new todoitem needs to be added with same specs of the one which needs to be changed,
            // but with different completed status

            std::string parsedline;
        //    std::string title = todoItem.getTitle();
        //    std::string description = todoItem.getDescription();
            std::string inpCompStatus;
            std::cout << "insert completed status " << std:: endl;
            std::cout << "[0] Todo not Completed" << std:: endl;
            std::cout << "[1] Todo Completed" << std:: endl;
            std::cin >> inpCompStatus;
            if(fileController.is_digits(inpCompStatus)) {
                if(inpCompStatus=="0"||inpCompStatus=="1") {
                    //delete the old todoitem
                    fileController.eraseFileLine(
                            fileController.parseLine(std::to_string(todoItem.getId()), todoItem.getTitle(),
                                                     std::to_string(todoItem.isCompleted()),
                                                     todoItem.getDescription()));

                    parsedline = fileController.parseLine(std::to_string(todoItem.getId()),
                                                          todoItem.getTitle(), inpCompStatus, todoItem.getDescription());
                    //adding to the txtfile
                    fileController.writeToFile(parsedline);
                 //   title.clear();
                 //   description.clear();


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
void showCompleted(FileController fileController){
    std::vector<TodoItem> vect;
    vect=fileController.readCompleted();
    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}
void showNotCompleted(FileController fileController){
    std::vector<TodoItem> vect;
    vect=fileController.readUncompleted();
    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}
void showAll(FileController fileController){
    std::vector<TodoItem> vect;
    vect=fileController.readFile();
    for(int i=0; i<vect.size();i++)
    {
        std::cout<< "["<<vect[i].getId()<< "] - ";
        std::cout<<vect[i].getTitle()<<std::endl;
        //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
        std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
        std::cout<<vect[i].getDescription()<<std::endl;
        std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<"---------------------"<<std::endl;

}
int main() {

   // std::string command;
    std::string command;
    std::string input;
    std::string file="TodoTextFile.txt";
    FileController fileController(file);
    bool menu = true;

 //   while (command!=0)
    while(menu)
    {

     //   std::cin.ignore(100, '\n');
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
        std::cin>> command;

        if(fileController.is_digits(command)) {
            int c = std::stoi(command);
            switch (c) {
                case 0:
                    std::cout << "esci " << std::endl;
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
                    std::cout << "Bad choice! Please try again: \n";
                    break;
            }
        }else{
            std::cout << "Input not valid. . . \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }


        //menu->quit
//        if(command=="q") {
//            break;
//        }else
            //menu->add
//        if(command=="a"){
            /*
            std::string parsedline;
            std::string title;
            std::string description;

            //Ask input details
            std::cin.ignore(1000, '\n');
            std::cout<<"Insert new todo "<<std::endl;

            std::cout<<"Insert title: "<<std::endl;
            while(title.empty() || title.find_first_not_of(' ')==std::string::npos || title.find_first_not_of('\t')==std::string::npos) {
                getline(std::cin, title);
            }

            std::cout<<"Insert description: "<<std::endl;
            while(description.empty() || description.find_first_not_of(' ') == std::string::npos || description.find_first_not_of('\t')==std::string::npos) {
                getline(std::cin, description);
            }

            //parsing line before writing into the text file
            parsedline = fileController.parseLine(fileController.getNextId(fileController.readFile()),title, std::to_string(0),description);

            //adding to the txtfile
            fileController.writeToFile(parsedline);
            title.clear();
            description.clear();

            std::cout<<"---------------------"<<std::endl;
             */
 //           addTodoItem(fileController);
 //       }else
            //menu->delete
 //       if(command=="b") {
 //           deleteTodo(fileController);
            /*
            // print the todolist in order to decide what to delete
                std::cout << "What do you want to delete ?" << std::endl;
                std::vector<TodoItem> vect;
                vect=fileController.readFile();
                for(int i=0; i<vect.size();i++)
                {
                    std::cout<< "["<<vect[i].getId()<< "] - ";
                    std::cout<<vect[i].getTitle()<<std::endl;
                    std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
                    std::cout<<vect[i].getDescription()<<std::endl;
                    std::cout<<"---------------------"<<std::endl;
                }
                std::cout<<"---------------------"<<std::endl;



            //Ask for the id
            std::cin.ignore(1000, '\n');
            std::cout << "Insert the id of the todo you want to delete: " << std::endl;
            getline(std::cin, input);

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
            */
 //       }else //change completed status
 //       if(command=="c"){
 //           changeCompletedStatus(fileController);
            /*
            std::cout << "Which todo needs to change its (completed) status?" << std::endl;
            std::vector<TodoItem> vect;
            vect=fileController.readFile();
            for(int i=0; i<vect.size();i++)
            {
                std::cout<< "["<<vect[i].getId()<< "] - ";
                std::cout<<vect[i].getTitle()<<std::endl;
                //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
                std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
                std::cout<<vect[i].getDescription()<<std::endl;
                std::cout<<"---------------------"<<std::endl;
            }
            std::cout<<"---------------------"<<std::endl;

            //Ask for the id
            std::cin.ignore(1000, '\n');
            std::cout << "Insert the id of the todo you want to change the (completed) status of: " << std::endl;
            getline(std::cin, input);

            if(fileController.is_digits(input)) {
                //find item to modify its status
                TodoItem todoItem;
                todoItem = fileController.findTodoById(fileController.readFile(), stoi(input));

                //check if it is found
                if (todoItem.getDescription() == "" && todoItem.getTitle() == "" && todoItem.isCompleted() == 0) {
                    std::cout << "todo not found" << std::endl;
                } else {
                    // a new todoitem needs to be added with same specs of the one which needs to be changed,
                    // but with different completed status

                    std::string parsedline;
                    std::string title = todoItem.getTitle();
                    std::string description = todoItem.getDescription();
                    std::string inpCompStatus;
                    std::cout << "insert completed status " << std:: endl;
                    std::cout << "[0] Todo not Completed" << std:: endl;
                    std::cout << "[1] Todo Completed" << std:: endl;
                    std::cin >> inpCompStatus;
                    if(fileController.is_digits(inpCompStatus)) {
                        if(inpCompStatus=="0"||inpCompStatus=="1") {
                            //delete the old todoitem
                            fileController.eraseFileLine(
                                    fileController.parseLine(std::to_string(todoItem.getId()), todoItem.getTitle(),
                                                             std::to_string(todoItem.isCompleted()),
                                                             todoItem.getDescription()));

                            parsedline = fileController.parseLine(fileController.getNextId(fileController.readFile()),
                                                                  title, inpCompStatus, description);
                            //adding to the txtfile
                            fileController.writeToFile(parsedline);
                            title.clear();
                            description.clear();


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

        */
//        }else //show completed
//                if(command=="d"){
//            showCompleted(fileController);
            /*
            std::vector<TodoItem> vect;
            vect=fileController.readCompleted();
            for(int i=0; i<vect.size();i++)
            {
                std::cout<< "["<<vect[i].getId()<< "] - ";
                std::cout<<vect[i].getTitle()<<std::endl;
                //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
                std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
                std::cout<<vect[i].getDescription()<<std::endl;
                std::cout<<"---------------------"<<std::endl;
            }
            std::cout<<"---------------------"<<std::endl;

        */
 //       }else //show not completed
 //       if(command=="e"){
 //           showNotCompleted(fileController);
            /*
            std::vector<TodoItem> vect;
            vect=fileController.readUncompleted();
            for(int i=0; i<vect.size();i++)
            {
            std::cout<< "["<<vect[i].getId()<< "] - ";
            std::cout<<vect[i].getTitle()<<std::endl;
            //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
            std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
            std::cout<<vect[i].getDescription()<<std::endl;
            std::cout<<"---------------------"<<std::endl;
        }
        std::cout<<"---------------------"<<std::endl;
            */


 //       }else //show all
 //       if(command=="f") {
 //           showAll(fileController);
            /*
            std::vector<TodoItem> vect;
            vect=fileController.readFile();
            for(int i=0; i<vect.size();i++)
            {
                std::cout<< "["<<vect[i].getId()<< "] - ";
                std::cout<<vect[i].getTitle()<<std::endl;
                //std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
                std::cout<<"Completed: "<<fileController.completedStatus(vect[i].isCompleted())<<std::endl;
                std::cout<<vect[i].getDescription()<<std::endl;
                std::cout<<"---------------------"<<std::endl;
            }
            std::cout<<"---------------------"<<std::endl;
             */
 //       }else{
 //           std::cerr<<"INPUT COMMAND NOT AVAILABLE. . . try again"<<std::endl;
 //       }


    }


    return 0;
}
