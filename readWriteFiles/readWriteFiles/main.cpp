//
//  main.cpp
//  readWriteFiles
//
//  Created by Affiq Mohammed on 12/3/22.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream outStream;
    outStream.open("test2.txt");
    outStream << "writing to file" << endl;
    cout << "new file";
    outStream.close();
    
    return 0;
}
