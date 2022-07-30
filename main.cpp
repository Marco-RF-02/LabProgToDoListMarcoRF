#include <iostream>
#include <fstream>
#include<string>
#include "TodoItem.h"
#include "FileController.h"

int main() {
    /*
    using namespace std;
    fstream myFile;
    myFile.open("TodoTextFile.txt",ios::out );
    if (myFile.fail()){
        cerr <<"Error occurred while opening the file..."<<endl;
        exit(1);
    }
    if (myFile.is_open()){
        myFile <<"Hello \n";
        myFile <<"This is the second line"<<endl;
        myFile.close();
    }
    myFile.open("TodoTextFile.txt", ios::app );
    if (myFile.is_open()){
        myFile <<"Hello2\n";
        myFile.close();
    }
    myFile.open("TodoTextFile.txt", ios::in );
    if (myFile.is_open()){
        string myLine;
        while(getline(myFile,myLine )){
            cout<< myLine<<endl;
        }
        myFile.close();
    }
*/

    std::string file="TodoTextFile.txt";
    FileController fileController(file);
    fileController.writeToFile("Do something");




    return 0;
}
