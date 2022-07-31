#include <iostream>
#include <fstream>
#include<string>
#include "TodoItem.h"
#include "FileController.h"


int main() {

    std::string command;
    std::string input;
    std::string file="TodoTextFile.txt";
    FileController fileController(file);

    while (command!="q")
    {
        //menu
        std::cout<<"This is your todo List menu"<<std::endl;
        std::cout<<"What would you like to do?"<<std::endl;
        std::cout<<"Insert the letter:"<<std::endl;
        std::cout<<"[q] Quit"<<std::endl;
        std::cout<<"[a] Add todo"<<std::endl;
        std::cout<<"[b] Delete todo"<<std::endl;
        std::cout<<"[c] Change completed status"<<std::endl;
        std::cout<<"[d] Show completed todo"<<std::endl;
        std::cout<<"[e] Show uncompleted todo"<<std::endl;
        std::cout<<"[f] Show all "<<std::endl;
        std::cin>>command;

        //menu->quit
        if(command=="q") {
            break;
        }else
            //menu->add
        if(command=="a"){

            std::string parsedline;
            std::string title;
            std::string description;

            //Ask input details
            std::cin.ignore(1000, '\n');
            std::cout<<"Insert todo: "<<std::endl;
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
        }else
            //menu->delete
        if(command=="b") {

            //Ask for the id
            std::cin.ignore(1000, '\n');
            std::cout << "Insert the id of the todo you want to delete: " << std::endl;
            getline(std::cin, input);

            //find item to delete
            TodoItem todoItem;
            todoItem = fileController.findTodoById(fileController.readFile(), stoi(input));

            //check if it is found
            if (todoItem.getDescription() == "" && todoItem.getTitle() == "" && todoItem.isCompleted() == 0) {
                std::cout << "todo not found" << std::endl;
            } else{

                //delete
                fileController.eraseFileLine(fileController.parseLine(std::to_string(todoItem.getId()),todoItem.getTitle(),
                                                                  std::to_string(todoItem.isCompleted()),todoItem.getDescription()));
                }
            std::cout<<"---------------------"<<std::endl;

        }else //test command (not in the menu)
        if(command=="t"){
            std::cin.ignore(1000, '\n');
            getline(std::cin, input);
            TodoItem todoItem;
            todoItem=fileController.findTodoById(fileController.readFile(),stoi(input));
            if(todoItem.getDescription()==""&&todoItem.getTitle()==""&&todoItem.isCompleted()==0){
                std::cout << "not found" << std::endl;
            }else {
                std::cout << todoItem.getId() << std::endl;
                std::cout << todoItem.getTitle() << std::endl;
                std::cout << todoItem.isCompleted() << std::endl;
                std::cout << todoItem.getDescription() << std::endl;
            }

        }else //change completed status
        if(command=="c"){

        }else //show completed
        if(command=="d"){

        }else //show not completed
        if(command=="e"){

        }else //show all
        if(command=="f") {
            std::vector<TodoItem> vect;
            vect=fileController.readFile();
            for(int i=0; i<vect.size();i++)
            {
                std::cout<< "["<<vect[i].getId()<< "] - ";
                std::cout<<vect[i].getTitle()<<std::endl;
                std::cout<<"Completed: "<<vect[i].isCompleted()<<std::endl;
                std::cout<<vect[i].getDescription()<<std::endl;
                std::cout<<"---------------------"<<std::endl;
            }
            std::cout<<"---------------------"<<std::endl;
        }else{
            std::cerr<<"INPUT COMMAND NOT AVAILABLE. . . try again"<<std::endl;
        }
    }


    return 0;
}
