#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void storeDeepThought(string dThought){
    ifstream tuyoFile;
    
    vector<string> theOldDeepThoughts;
    
    tuyoFile.open("deepNotes.txt");
    string oldDeepThought;
    
    while(!tuyoFile.eof()){
        getline(tuyoFile, oldDeepThought);
        //cout << oldDeepThought << endl;
        
        theOldDeepThoughts.push_back(oldDeepThought);
    }
    //cout << "end of file" << endl;
    tuyoFile.close();
    
    for(int i = 0; i < theOldDeepThoughts.size(); i++){
        cout << theOldDeepThoughts[i]  << endl;
    }
    
    ofstream mioFile;
    mioFile.open("deepNotes.txt");
    for(int i = 0; i < theOldDeepThoughts.size(); i++){
        mioFile << theOldDeepThoughts[i] << endl;
    }
    mioFile << dThought << endl;
    mioFile.close();
}

int main(int argc, char *argv[]){
    cout << "Tell me a deep thought" << endl;
    string dThought;
    
    if(argc > 1){
        dThought = argv[1];
    }
    else{
    getline(cin, dThought);
    }
    
    storeDeepThought(dThought);
    
    cout << "Deep thought: " << dThought << endl;
    
}