#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include "TodoList.h"

using namespace std;

TodoList::TodoList() {
    
    ifstream myfile("Todo.txt");
    
    string str;
    while( getline(myfile, str))
    {
        if(str.size() > 0)
            fileContents.push_back(str);
    }
    myfile.close();
}

TodoList::~TodoList(){
    ofstream myfile("Todo.txt");
    for (int i = 0; i < fileContents.size(); i++) {
        myfile << fileContents[i] << endl;
    }
}

void TodoList::add(string _duedate, string _task){
    fileContents.push_back(_duedate);
    fileContents.push_back(_task);
}

int TodoList::remove(string _task){
    int erasedSomething = 0;
    for (int i = 0; i < fileContents.size(); i++) {
        if(fileContents[i] == _task){
            fileContents.erase(fileContents.begin() + i - 1);
            fileContents.erase(fileContents.begin() + i - 1);
            i = i - 1;
            erasedSomething = 1;
        }
    }
    return erasedSomething;
}

void TodoList::printTodoList(){
    for (int i = 0; i < fileContents.size(); i++) {
        cout << fileContents[i] << " ";
        if(i%2 == 1)
            cout << endl;
    }
}

void TodoList::printDaysTasks(string _date){
    for (int i = 0; i < fileContents.size(); i+=2) {
        if(fileContents[i] == _date)
            cout << fileContents[i] << "  " << fileContents[i+1] << endl;
    }
}