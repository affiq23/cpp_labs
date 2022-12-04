//
//  main.cpp
//  gradeTest
//
//  Created by Affiq Mohammed on 12/2/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

void displayResults(char arr1[], char arr2[], int numLines){
    
    int incorrectAns = 0;
    double totalGrade = 0;
    
    for(int i = 0; i < numLines; i++){
        if(arr1[i] != arr2[i]){
            cout << "Question " << i << " has incorrect answer '" << arr2[i] << "', the correct answer is '" << arr1[i] << "'." << endl;
            incorrectAns++;
        }
    }
    cout << incorrectAns << " were missed out of " << numLines << endl;
}



int main() {
    
    string key;
    string responses;
    int keyAnswers = 0;
    int resAnswers = 0;
    int numKeyLines = 0;
    string keyLine;
    int numResLines = 0;
    string resLine;
    
    cout << "Enter the name of the file containing the key." << endl;
    cin >> key;
    fstream keyFile;
    keyFile.open(key, ios::in);
    
    if(keyFile.is_open()){
        while(getline(keyFile, keyLine)){
            numKeyLines++;
        }
    }
    
    char keyArr[numKeyLines];
    
    //checking if key file is valid and can be opened
    if(keyFile.is_open()){
        char val;
        
        while(!keyFile.eof()){
           
            keyFile.get(val);
            keyArr[keyAnswers] = val;
            keyAnswers++;
        }
        keyFile.close();
    }
    else{
        cout << key << " could not be opened." << endl;
    }
    
    cout << "Enter the name of the file containing the responses." << endl;
    cin >> responses;
    fstream responseFile;
    responseFile.open(responses, ios::in);
    
    if(responseFile.is_open()){
        while(getline(responseFile, resLine)){
            numResLines++;
        }
    }
    
    char resArr[numResLines];
    
    //checking if responses file is valid and can be opened
    if(responseFile.is_open()){
        char val;
        
        while(!responseFile.eof()){
            
            responseFile.get(val);
            resArr[resAnswers] = val;
            resAnswers++;
        }
        responseFile.close();
    }
    else{
        cout << responses << " could not be opened." << endl;
    }
    
    if(numKeyLines == numResLines){
        displayResults(keyArr, resArr, numKeyLines);
    }
    else{
        cout << "File error! There is a mismatch between the number of questions and answers." << endl;

    }
    
   
    return 0;
}
