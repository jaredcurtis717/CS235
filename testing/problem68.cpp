#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    int num = stoi(argv[1]);
    cout << num << " ";
    for(int i = 0; i < 400; i++){
        if(num % 2 == 0)
            num = num / 2;
        else
            num = num * 3 + 1;
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}