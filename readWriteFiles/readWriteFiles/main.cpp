//
//  main.cpp
//  readWriteFiles
//
//  Created by Affiq Mohammed on 12/3/22.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    fstream outStream;
    
    outStream.open("test2.txt", ios::in);
    
    if(outStream.is_open()){
        string line;
        while(getline(outStream, line)){
            cout << line << endl;
        }
        outStream.close();
    }
    
    return 0;
}
