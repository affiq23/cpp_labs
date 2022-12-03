//
//  main.cpp
//  CourseGrade
//
//  Created by Affiq Mohammed on 12/2/22.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {

  
   string infoFile;
   cin >> infoFile;
    
     ifstream inputFile(infoFile);
     string outFile = "report.txt";
     
     if (inputFile.is_open()) {
        string lastName;
        string firstName;
         
        int midterm1;
        int midterm2;
        int finalGrade;
        double average;
        int midterm1Total = 0;
        int midterm2Total = 0;
        int finalTotal = 0;
        int icrem = 0;
        
        ofstream outputFile(outFile);
        
        while (inputFile >> lastName >> firstName >> midterm1 >> midterm2 >> finalGrade) {
           midterm1Total += midterm1;
           midterm2Total += midterm2;
           finalTotal += finalGrade;
           icrem++;
           outputFile << lastName << "\t" << firstName << "\t" << midterm1 << "\t" << midterm2 << "\t" << finalGrade << "\t";
           
           average = (midterm1 + midterm2 + finalGrade) / 3.0;
           
           if (average < 60) {
              outputFile << "F" << endl;
           }
           else if (average < 70) {
              outputFile << "D" << endl;
           }
           else if (average < 80) {
              outputFile << "C" << endl;
           }
           else if (average < 90) {
              outputFile << "B" << endl;
           }
           else {
              outputFile << "A" << endl;
           }
         }

        outputFile << endl;
        outputFile << fixed << setprecision(2) << "Averages: midterm1 " << midterm1Total * 1.0 / icrem << ", ";
        outputFile << fixed << setprecision(2) << "midterm2 " << midterm2Total * 1.0 / icrem << ", ";
        outputFile << fixed << setprecision(2) << "final " << finalTotal * 1.0 / icrem << endl;
    }

   return 0;
}
