#include "oppg1.h"

bool isTxtFile(string string){
    if(string.length() >= 5){
        return (0 == string.compare(string.length() - 4, 4, ".txt"));
    }
    else{
        return false;
    }
}

void inputToFile(){
    filesystem::path fileName{"oppg1a.txt"};
    ofstream outputStream{fileName};
    cout << "Write quit to end" << endl;
    string word;
    while(word != "quit"){
        cout << "Sentence: ";
        getline(cin, word);
        for(int i = 0; i < word.size(); i++){
            word[i] = tolower(word[i]);
        }
        if(word != "quit"){
            outputStream << word << endl;
        }
    }
}

void addLineNum(){
    string file;
    bool legalFile = false;
    ifstream fileIn;
    while(!legalFile){    
        cout << "File to read: ";
        cin >> file;
        fileIn.open(file);
        if(fileIn){
            ifstream fileIn(file);
            legalFile = true;
        }
        else{
            cout << "Could not find file" << endl;
        }
    }
    legalFile = false;
    while(!legalFile){
        cout << "Save to: ";
        cin >> file;
        if(isTxtFile(file)){
            legalFile = true;
        }
        else{
            cout << "Must be .txt file" << endl;
        }
        
    }
    ofstream fileOut(file);

    int i = 1;
    string line;
    while(getline(fileIn, line)){
        fileOut << i++ << ". " << line << endl; 
    } 
}


bool testFile(filesystem::path fileName, ifstream& is){
    string pathString = fileName.string();
    if(!isTxtFile(pathString)){
        cout << "File is not a .txt file!" << endl;
        return false;
    }
    is.close();
    is.open(fileName);
    if(!is){
        cout << "Could not open file" << endl;
        return false;
    }
    is = fileName;
    return true;

}

