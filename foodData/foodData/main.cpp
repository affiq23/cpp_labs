//
//  main.cpp
//  foodData
//
//  Created by Affiq Mohammed on 12/2/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>


using namespace std;

int main() {


   string infoFile;
   cin >> infoFile;
     ifstream inputFile(infoFile);

     if (inputFile.is_open()) {
        string line;
        string category;
        string name;
        string descrb;
        string availability;
        string check = "Not available";

        while (getline(inputFile, line)) {
          if (line.find(check) == string::npos) {
             int pos = line.find("\t");
             category = line.substr(0, pos);
             int pos2 = line.find("\t", pos + 4) - pos;
             name = line.substr(pos + 1, (pos2 - 1));
             int pos3 = line.find("\t", pos2 + pos + 4);
             descrb = line.substr(pos2 + pos + 1, pos3 - (pos2 + pos + 1));
            cout << name << " (" << category << ") -- " << descrb << endl;
          }
         }


    }

   return 0;
}

