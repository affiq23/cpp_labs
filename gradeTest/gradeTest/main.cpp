//
//  main.cpp
//  gradeTest
//
//  Created by Affiq Mohammed on 12/2/22.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main() {
    
    string key;
    string responses;
    char keyArr[50];
    char resArr[50];
    
    cout << "Enter the name of the file containing the key." << endl;
    cin >> key;
    
    
    fstream keyFile;
    keyFile.open(key, ios::in);
    
    
    //checking if key file is valid and can be opened
    if(keyFile.is_open()){
        string line;
        int i = 0;
        char val;
        
        while(!keyFile.eof()){
           
            keyFile.get(val);
            keyArr[i] = val;
            i++;
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
    
    
    //checking if responses file is valid and can be opened
    if(responseFile.is_open()){
        string line;
        int i = 0;
        char val;
        
        while(!responseFile.eof()){
            
            responseFile.get(val);
            resArr[i] = val;
            i++;
        }
        responseFile.close();
    }
    else{
        cout << responses << " could not be opened." << endl;
    }
    
    
    
    
   
    return 0;
}
