#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <vector>

using namespace std;

void outputVectorTxtFile(string str, vector<string>& vec){
    ofstream wordsInVectorList;
    string textFileNameVector = str;
    textFileNameVector.append("_vector.txt");
    wordsInVectorList.open(textFileNameVector);
    for(int i = 0; i < vec.size(); i++)
    {
        wordsInVectorList << vec[i] << endl;;
    }
    wordsInVectorList.close();
}

void outputSetTxtFile(string str, set<string>& st){
    ofstream wordsInList;
    string textFileName = str;
    textFileName.append("_set.txt");
    wordsInList.open(textFileName);
    for(set<string>::iterator it = st.begin(); it != st.end(); it++)
    {
        wordsInList << *it << endl;;
    }
    wordsInList.close();
}

void readFromNewFile(set<string>& setOfWords, vector<string>& vectorOfWords){
    ifstream file;
    file.open ("newText.txt");
    //if (!file.is_open()) return 0;
    string word;
    while (file >> word)
    {
        setOfWords.insert(word);
        vectorOfWords.push_back(word);
    }
    file.close();
}

void generateNewFile(string& fileContents){
    ofstream newFile;
    newFile.open("newText.txt");
    for (int i = 0; i < fileContents.length(); i++) {
        if(isalpha(fileContents.at(i)) || fileContents.at(i) == ' ' || fileContents.at(i) == '\n'){
            newFile << fileContents.at(i);
        }
    }
    newFile.close();
}

void readOriginalFile(string& fileContents, string filename){
    ifstream textFile;
    textFile.open(filename);
    
    string line;
    while(getline(textFile,line)){
        fileContents.append(line);
        fileContents.append("\n");
        
    }
    //getline(textFile,fileContents);
    textFile.close();
}

void outputMapTxtFile(string filename, vector<string>& vectorOfWords, map<list<string>, vector<string>> &wordMap, int M){
    
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
                        
    for (vector<string>::iterator it = vectorOfWords.begin(); it != vectorOfWords.end(); it++) {
        wordMap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }
    
    ofstream mapOutput;
    string mapOutputName = filename;
    mapOutputName.append("_1_1.txt");
    mapOutput.open(mapOutputName);
    for(map<list<string>, vector<string>>::iterator mapIt = wordMap.begin(); mapIt != wordMap.end(); mapIt++){
        for(list<string>::const_iterator it = mapIt->first.begin(); it != mapIt->first.end(); it++){
            mapOutput << it->c_str() << " ";
        }
        mapOutput << ", ";
        for(int i = 0; i < mapIt->second.size(); i++)
            mapOutput << mapIt->second[i] << ",";
        mapOutput << endl;
    }
    mapOutput.close();
}

int main(int argc, char *argv[]){
    
    if (argc != 2)
    {
        cout << "Invalid arguments" << endl;
        return 0;
    }
    string fileContents;
    
    readOriginalFile(fileContents, argv[1]);
    
    generateNewFile(fileContents);
    
    set<string> setOfWords; 
    vector<string> vectorOfWords;
    
    readFromNewFile(setOfWords, vectorOfWords);
    
    outputSetTxtFile(argv[1], setOfWords);
    
    outputVectorTxtFile(argv[1], vectorOfWords);
    
    int M = 2;
    map<list<string>, vector<string>> wordMap;
    outputMapTxtFile(argv[1], vectorOfWords, wordMap, M);
    
    
    srand(time(NULL)); 
                       
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordMap[state].size();
        cout << wordMap[state][ind]<<" ";
        state.push_back(wordMap[state][ind]);
        state.pop_front();
    }
    cout << endl;
            
    return 0;
}

