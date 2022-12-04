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
    
    ofstream newFile;
    newFile.open("newTextFile.txt");
    
    if(!newFile.is_open()){
        cout << "file is not open\n";
    }
    
    newFile << "new data\n";
    newFile.close();
    return 0;
    
    
}
