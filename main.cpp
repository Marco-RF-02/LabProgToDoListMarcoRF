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


        if(command=="q") {
            break;
        }else
        if(command=="a"){
            std::cin.ignore(1000, '\n');
            std::cout<<"Insert todo: "<<std::endl;
            getline(std::cin, input);
            fileController.writeToFile(input);
            std::cout<<"---------------------"<<std::endl;
        }else
        if(command=="b"){

        }else
        if(command=="c"){

        }else
        if(command=="d"){

        }else
        if(command=="e"){

        }else
        if(command=="f") {
            fileController.readFile();
            std::cout<<"---------------------"<<std::endl;
        }else{
            std::cerr<<"INPUT COMMAND NOT AVAILABLE. . . try again"<<std::endl;
        }
    }


  //  std::string file="TodoTextFile.txt";
  //  FileController fileController(file);

  //  fileController.readFile();

  // fileController.eraseFileLine("Do something 2");





    return 0;
}
