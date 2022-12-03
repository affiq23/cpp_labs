//
//  main.cpp
//  adjustList
//
//  Created by Affiq Mohammed on 11/3/22.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    
    vector<double> myDoubleVec;
    vector<double> myNewVec;
    int num;
    double input = 0.0;
    double largestVal;
    
    cin >> num;
    
    for(int i = 0; i < num; i++){
        cin >> input;
        myDoubleVec.push_back(input);
    }
    
    largestVal = myDoubleVec.at(0);
    
    for(int i = 0; i < myDoubleVec.size(); i++){
        if(largestVal < myDoubleVec.at(i)){
            largestVal = myDoubleVec.at(i);
        }
    }
    
    for(int i = 0; i < myDoubleVec.size(); i++){
        myNewVec.push_back(myDoubleVec.at(i)/largestVal);
        cout << fixed << setprecision(2) << myNewVec.at(i) << " ";
    }
    

    cout << endl;
    
    
    return 0;
}
