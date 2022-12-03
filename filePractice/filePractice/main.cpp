//
//  main.cpp
//  filePractice
//
//  Created by Affiq Mohammed on 11/22/22.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream inputFile;
    inputFile.open("newFile.txt");
    
    cout << "printing to file" << endl;
    
    inputFile << "this is a new line" << endl;
    inputFile << "now i want to see if it works again" << endl;
    inputFile.close();
    
    cout << "done";
    return 0;
    
    
}
