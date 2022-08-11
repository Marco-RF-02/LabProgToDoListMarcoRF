#include <iostream>
#include<string>


#include<algorithm>
#include "Date.h"
#include "FileController.h"
#include "Todolist.h"



std::string removeSpaces(std::string input) // this func is used to remove spaces from string input
{
    input.erase(std::remove(input.begin(),input.end(),' '),input.end()); // remove spaces
    input.erase(std::remove(input.begin(),input.end(),'\t'),input.end());// remove tabs
    return input;
}

std::string getInputText() { // this is used to control various wrong inputs from user
    std::string input;
    while(input.empty() || input[0]==' '||input[0]=='\t' || input.find_first_not_of(' ')==std::string::npos || input.find_first_not_of('\t')==std::string::npos) {
        getline(std::cin, input);
    }
    return input;
}

Date getInputDate(){
    int day, month, year;
    std::cout << "please enter the date in this format day month year ""d m yyyy"" (ex. 1 1 2022)" << std::endl;
    Date date;
    while(true) {

        std::cin >> day >> month >> year;


          if (date.checkDate(day, month, year)) {
              std::cout << " - The date is valid!  " << std::endl;
              date.setDay(day);
              date.setMonth(month);
              date.setYear(year);
              break;

          }else {
            std::cout << " - Format or date not valid. try again"<<std::endl;
              std::cin.clear();
              std::cin.ignore(1000, '\n');
        }
    }
    return date;
}

void addTodoItem(FileController fileController){ // add new todoitem
    std::string parsedline;
    std::string title;
    std::string description;
    std::string category;
    Date date;

    //Ask input details

    std::cout<<"Insert new todo "<<std::endl;
    std::cout<<"Insert title: "<<std::endl;
    title=getInputText();

    std::cout<<"Insert description: "<<std::endl;
    description=getInputText();

    std::cout<<"Insert date: "<<std::endl;
    date =getInputDate();

    std::cout<<"Insert category: "<<std::endl;
    category =getInputText();


    //parsing line before writing into the text file
    parsedline = fileController.parseLine(title, std::to_string(0),description,fileController.parseDate(date.getDay(),date.getMonth(),date.getYear()),category);
    std::string opparsedline = fileController.parseLine(title, std::to_string(1),description,fileController.parseDate(date.getDay(),date.getMonth(),date.getYear()),category);

    //check if already added
    Todolist todolist(fileController.readFile());
    if(todolist.findByParsedLine(parsedline,opparsedline,fileController)){
        std::cout << "Cannot fulfill the request, Sorry! the todo you want to add is already saved.  " << std::endl;
    }else {
        //adding to the txtfile
        fileController.writeToFile(parsedline);
    }
    std::cout<<"---------------------"<<std::endl;
}

void showAll(FileController fileController){

    Todolist todoList(fileController.readFile());
    todoList.printTodoItemList();

}
void showByCategory(FileController fileController, int c){

    std::list<std::string> categoryList = fileController.categoryList();
    Todolist todoList(fileController.readFile());

    for(const auto& itr : categoryList){
        std::cout<<"________________________________________"<<std::endl;
        std::cout<<"Category: "<<itr<<std::endl;
        std::cout<<"________________________________________"<<std::endl;
        for(const auto& i : todoList.getTodoitemsList()) {
            if(itr == i.getCategory()) {
                if(i.isCompleted()&&c==1) {
                    std::cout << i.getTitle() << std::endl;
                    std::cout << i.getDescription() << std::endl;
                    std::cout << i.getDate().getDay() << " " << i.getDate().getMonth() << " " << i.getDate().getYear()
                              << std::endl;
                    std::cout << ".........." << std::endl;
                }
                if(!i.isCompleted()&& c==0){
                    std::cout << i.getTitle() << std::endl;
                    std::cout << i.getDescription() << std::endl;
                    std::cout << i.getDate().getDay() << " " << i.getDate().getMonth() << " " << i.getDate().getYear()
                              << std::endl;
                    std::cout << ".........." << std::endl;
                }
                if(c==2){
                    std::cout << i.getTitle() << std::endl;
                    std::cout << i.getDescription() << std::endl;
                    std::cout << i.getDate().getDay() << " " << i.getDate().getMonth() << " " << i.getDate().getYear()
                              << std::endl;
                    std::cout << "completed: " << todoList.completedStatus(i.isCompleted()) << std::endl;
                    std::cout << ".........." << std::endl;
                }

            }
        }

    }
    if(c==0)
        std::cout<<"********** Total of Todo Not Completed: "<<std::to_string(todoList.countNotCompleted())<<" **************"<<std::endl;
    if(c==1)
        std::cout<<"********** Total of Todo Completed: "<<std::to_string(todoList.countCompleted())<<" **************"<<std::endl;


}

void deleteTodo(FileController fileController){

    std::string input;
    // print the todolist in order to decide what to delete
    std::cout << "What do you want to delete ?" << std::endl;
    Todolist todolist (fileController.readFile());
    todolist.printTodoItemList();

    // ask for the id
    std::cout << "Insert the id of the todo you want to delete: " << std::endl;
    input = getInputText();

    if(fileController.isDigits(input)) {
        //find item to delete
        TodoItem todoItem;
        todoItem = todolist.getTodoToDelete( stoi(input));

        //check if it is found
        if (todoItem.getDescription().empty() && todoItem.getTitle().empty() && todoItem.isCompleted() == 0 && todoItem.getCategory().empty()) {
            std::cout << "sorry, todo not found" << std::endl;

        } else {

            //delete
            bool done = fileController.eraseFileLine(
                    fileController.parseLine( todoItem.getTitle(),
                                             std::to_string(todoItem.isCompleted()),
                                             todoItem.getDescription(),
                                             fileController.parseDate(todoItem.getDate().getDay(),
                                                                      todoItem.getDate().getMonth(),
                                                                      todoItem.getDate().getYear()),
                                                                      todoItem.getCategory()));
            if(done)
                std::cout<<"Deleting Todo -> Done!"<<std::endl;
        }
    }else{
        std::cerr << "input not valid. . ." << std::endl;
    }
    std::cout<<"---------------------"<<std::endl;
}
void changeCompletedStatus(FileController fileController){
    std::string input;
    std::cout << "Which todo needs to change its (completed) status?" << std::endl;
    Todolist todolist(fileController.readFile());
    todolist.printTodoItemList();


    // ask for the id
    std::cout << "Insert the number of the todo you want to change the (completed) status of: " << std::endl;
    input = getInputText();
    input = removeSpaces(input);

    if(fileController.isDigits(input)) {
        //find item to modify its status
        TodoItem todoItem;
        todoItem = todolist.getTodoToDelete( stoi(input));

        //check if it is found
        if (todoItem.getDescription().empty() && todoItem.getTitle().empty() && todoItem.isCompleted() == 0) {
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

            if(fileController.isDigits(inpCompStatus)) {
                if(inpCompStatus=="0"||inpCompStatus=="1") {

                    parsedline = fileController.parseLine(todoItem.getTitle(),
                                                          std::to_string(todoItem.isCompleted()),
                                                          todoItem.getDescription(),
                                                          fileController.parseDate(todoItem.getDate().getDay(),
                                                                                   todoItem.getDate().getMonth(),
                                                                                   todoItem.getDate().getYear()),
                                                                                   todoItem.getCategory());
                   std::string  newparsedline = fileController.parseLine(todoItem.getTitle(),
                                                          inpCompStatus,
                                                          todoItem.getDescription(),
                                                          fileController.parseDate(todoItem.getDate().getDay(),
                                                                                   todoItem.getDate().getMonth(),
                                                                                   todoItem.getDate().getYear()),
                                                          todoItem.getCategory());

                   bool done = fileController.changeCompletedStatus(parsedline, newparsedline);

                    if(done) {
                        std::cout<<"Update ->Done!"<<std::endl;
                    }

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

int main() {


    std::string command;
    std::string input;
    std::string file  = "TodoTextFile.txt";
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
        std::cout<<"[7] Show all By Category"<<std::endl;

        try { // there are already multiple controls but this try-catch block gives us more safety
            command = getInputText();
            command = removeSpaces(command);
        }catch (std::exception& e){
            std::cerr << "Input error. . . \n";
        }

        if(fileController.isDigits(command)) {
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
                        showByCategory(fileController,1);
                        break;
                    case 5:
                        showByCategory(fileController,0);
                        break;
                    case 6:
                        showAll(fileController);
                        break;
                    case 7:
                        showByCategory(fileController,2);
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