
#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include "TodoList.h"

using namespace std;

TodoList::TodoList() {
    
    ifstream myfile("Todo.txt");
    int counter = 0;
    while(!myfile.eof()){
        getline(myfile, fileContents[counter]);
        counter++;
    }
    myfile.close();
}

TodoList::~TodoList(){
    ofstream myfile("Todo.txt");
    for (int i = 0; i < fileContents.size(); i++) {
        myfile << fileContents[i] << endl;
    }
}

/*void TodoList::add(){
    
}
*/
