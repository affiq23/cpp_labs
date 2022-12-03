//
//  main.cpp
//  CoinFlipping
//
//  Created by Affiq Mohammed on 10/27/22.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    
    int times = 0;
    int randomNumber = 0;
    bool check = true;
    
    int heads = 0;
    int tails  = 0;
    string cond;
    unsigned int seed;
    cin >> seed;
    
    
    
    srand(seed);//seeding the random number generator
    
    while(check){
        
        times++;
        
        randomNumber = 1 + rand() % 2;
        
        if(randomNumber == 1){
            heads++;
            cout << "Flip = Heads" << endl;
        }
        else{
            cout << "Flip = Tails" << endl;
            tails++;
        }
        
        cout << "Do you want to flip again?" << endl;
        cout << "Y for Yes" << endl;
        cout << "N for No" << endl;
        cin >> cond;
        cout << endl;
        
        if((cond == "Y") || (cond == "y")){
            check = true;
        }
        else if((cond == "N") || (cond == "n")){
            check = false;
        }
        
        else {
            int val = 0;
            while(val == 0){
                
                cout << "Your input is invalid" << endl;
                cin >> cond;
                if((cond == "Y") || (cond == "y")){
                    val = 1;
                }
                else if((cond == "N") || (cond == "n")){
                    val = 1;
                }
            }
            
            check = true;
        }
    }
        
        double headValue = (1.0 * heads/times) * 100;
        double tailValue = (1.0 * tails/times) * 100;
        
        cout << heads << " of the " << times << " flips were Heads or " << fixed << setprecision(1) << headValue << "% were Heads." << endl;
        cout << tails << " of the " << times << " flips were Tails or " << fixed << setprecision(1) << tailValue << "% were Tails." << endl;
        return 0;
        
    }

