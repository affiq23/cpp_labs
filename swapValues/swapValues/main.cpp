//
//  main.cpp
//  rangeInputs
//
//  Created by Affiq Mohammed on 11/3/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> myIntVec;
    
    int num;
    int input = 0;
    int lowBound;
    int upBound;
    
    cin >> num;
    
    
    for(int i = 0; i < num; i++){
        cin >> input;
        myIntVec.push_back(input);
    }
    
    cin >> lowBound;
    cin >> upBound;
    
    for(int i = 0; i < myIntVec.size(); i++){
        if(myIntVec.at(i) >= lowBound && myIntVec.at(i) <= upBound){
            cout << myIntVec.at(i) << ",";
        }
    }
    cout << endl;
    

    return 0;
}
