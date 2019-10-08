#include <iostream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]){
    TodoList list;
    //cout << argv[1] << endl;
    
    if (argc > 1){
        if(string(argv[1])  == "add")
            list.add(argv[2], argv[3]);
            
        else if(string(argv[1]) == "remove"){
            int erasedSomething = list.remove(argv[2]);
            if(erasedSomething)
                cout << "Erased Succesfully" << endl;
            else
                cout << "Could not find task to erase" << endl;
        }
        
        else if(string(argv[1]) == "printList")
            list.printTodoList();
        
        else if(string(argv[1]) == "printDay")
            list.printDaysTasks(argv[2]);
        
        else
            cout << "Invalid method call" << endl;
        }
    else
    {
        cout << "Not enough arguments" << endl;
    }

    return 0;
}