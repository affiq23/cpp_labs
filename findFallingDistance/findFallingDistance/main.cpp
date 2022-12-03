//
//  main.cpp
//  FindFallingDistance
//
//  Created by Affiq Mohammed on 11/19/22.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getSeconds(){
    double secs;
    
    cout << "Please enter the fall time (in seconds): ";
    cin >> secs;
    
    if(secs < 0){
        while(secs < 0){
            cout << "Error the fall time must be 0 or more." << endl;
            cout << "Please enter the fall time (in seconds): ";
            cin >> secs;
        }
    }
    return secs;
}

double findEarthFallDist(double seconds){
    double distance;
    distance = 0.5 * 9.81 * (pow(seconds, 2));
    return distance;
}

double findMoonFallDist(double seconds){
    double distance;
    distance = 0.5 * 1.625 * (pow(seconds, 2));
    return distance;
}

//displayResults displays the distance an object on Earth and the Moon travels, and the amount of time it takes. It takes the distance on the Earth and Moon, and the amount of time as inputs, and outputs it in sentences.
void displayResults(double earthDist, double moonDist, double seconds){
    cout << "The object traveled " << fixed << setprecision(3) << earthDist << " meters in " << fixed << setprecision(1) << seconds << " seconds on Earth." << endl;
    cout << "The object traveled " << fixed << setprecision(3) << moonDist << " meters in " << fixed << setprecision(1) << seconds << " seconds on the Moon." << endl;
}

int main() {
    
    double seconds = getSeconds();
    cout << endl;
    double earthDist = findEarthFallDist(seconds);
    double moonDist = findMoonFallDist(seconds);
    displayResults(earthDist, moonDist, seconds);
    

    return 0;
}
