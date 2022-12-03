//
//  main.cpp
//  FindPresentVal
//
//  Created by Affiq Mohammed on 11/19/22.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int readYears(){
    int years;
    cout << "Enter the whole number of years of the investment: ";
    cin >> years;
    
    if(years <= 0){
        while(years <= 0){
            cout << "Error the number of years must be greater than zero." << endl;
            cout << "Enter the whole number of years of the investment: ";
            cin >> years;
        }
    }
    
    return years;
}

double presentValue(double futureValue, double interestRate, int numberYears){
    
    double presVal = futureValue / (pow((1 + interestRate), numberYears));
    return presVal;
}

void displayResults(double presentValue, double futureValue, double interestRate, int numberYears){
    
    cout << "Present value: $" << fixed << setprecision(2) << presentValue << endl;
    cout << "Years: " << numberYears << endl;
    cout << "Annual interest rate: " << fixed << setprecision(3) << (interestRate * 100) << "%" << endl;
    cout << "Future value: $" << fixed << setprecision(2) << futureValue << endl;
}

int main() {
    
    double futureVal;
    double rate;
    
    cout << "Enter the future value of the investment: ";
    cin >> futureVal;
    
    if(futureVal < 0){
        while(futureVal < 0){
            cout << "Error the future value must be greater than zero." << endl;
            cout << "Enter the future value of the investment: ";
            cin >> futureVal;
        }
    }
    
    cout << "Enter the annual interest rate: ";
    cin >> rate;
    
    if(rate < 0){
        while(rate < 0){
            cout << "Error the annual interest rate must be greater than zero." << endl;
            cout << "Enter the annual interest rate: ";
            cin >> rate;
        }
    }
    
    rate = rate / 100;
    
    int years = readYears();
    double presentVal = presentValue(futureVal, rate, years);
    displayResults(presentVal, futureVal, rate, years);
    
    
    return 0;
}
