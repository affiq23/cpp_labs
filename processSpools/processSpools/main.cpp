//
//  main.cpp
//  ProcessSpoolsOrder
//
//  Created by Affiq Mohammed on 12/1/22.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

 double defaultHandlingCharge = 20.95;

double calcShipping(int order, double sCost = defaultHandlingCharge);


//gets order amount based on how many in stock
int getOrderAmt(int order, int stock){
    int orderNum = 0;
    if(order > stock){
        orderNum = stock;
    }
    if(order == stock){
        orderNum = order;
    }
    if(order < stock){
        orderNum = order;
    }
    return orderNum;
}

//gets # of spools on back order by checking stock
int getBackOrder(int order, int stock){
    int backNum;
    if(order == stock){
        backNum = 0;
    }
    if(order > stock){
        backNum = order - stock;
    }else{
        backNum = 0;
    }
    return backNum;
}

//gets total price
double getTotalPrice(int order){
    double total = order * 157.55;
    return total;
}

//gets shipping price
double calcShipping(int order, double sCost){
    double total = order * sCost;
    return total;
}

//calculates the spools for shipping and all the price breakdowns
void displayResults(int order, int stock, double shipping){
    int orderAmount;
    int backOrder;
    double orderTotal;
    double shippingTotal = shipping;
    double finalTotal;
    orderAmount = getOrderAmt(order, stock);
    backOrder = getBackOrder(order, stock);
    
    cout << endl;
    
    cout << "Spools ready for shipping: " << orderAmount << endl;
    
    if(backOrder > 0){
        cout << "Spools on back order: " << backOrder << endl;
    }
    
    orderTotal = getTotalPrice(orderAmount);
    cout << fixed << setprecision(2) << "Charges for " << orderAmount << " spools: $" << orderTotal << endl;
    
    //shippingTotal = calcShipping(orderAmount, shipping);
    cout << fixed << setprecision(2) << "Shipping and handling for " << orderAmount << " spools: $" << shippingTotal << endl;
    
    finalTotal = orderTotal + shippingTotal;
    cout << fixed << setprecision(2) << "Total charges (Incl. shipping & handling): $" << finalTotal << endl;
}

//getOrder function checks if there is custom handling charge and how many spools
void getOrder(int& order, int& stock, char& userChoice, double& handling){
   
    char customShipping;
    double shippingTotal;
    int orderAmount;
    
    cout << "Please enter the number of spools ordered: ";
    cin >> order;
    while(order < 1){
        if(order < 1){
            cout << "Error, the number of spools must be at least 1." << endl;
            cout << "Please enter the number of spools ordered: ";
            cin >> order;
        }
    }
    
    cout << "Please enter the number of spools in stock: ";
    cin >> stock;
    while(stock < 0){
        if(stock < 0){
            cout << "Error, the spools in stock should be 0 or more." << endl;
            cout << "Please enter the number of spools in stock: ";
            cin >> stock;
        }
    }
    
    //orderAmount = getOrderAmount(nSPools, nStock);
    
    cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
    cin >> userChoice;
    
    if((userChoice == 'Y') || (userChoice == 'y')){
        customShipping = 'Y';
        cout << "What is the shipping and handling charge? ";
        cin >> handling;
        while(handling < 0.00){
            if(handling < 0.00){
                cout << "Error, the charge must be at least $0.00." << endl;
                cout << "What is the shipping and handling charge? ";
                cin >> handling;
            }
        }
        
    }
    if((userChoice == 'N') || (userChoice == 'n')){
        customShipping = 'N';

    }
    
    userChoice = customShipping;
}

int main(){
    int numSpools;
    int numStock;
    char userInput;
    double handling;
    double shippingTotal;
    int orderAmount;
    
    
    getOrder(numSpools, numStock, userInput, handling);
    
    if(userInput == 'Y'){
        orderAmount = getOrderAmt(numSpools, numStock);
        shippingTotal = calcShipping(orderAmount, handling);
        displayResults(numSpools, numStock, shippingTotal);
    }
    if(userInput == 'N'){
        orderAmount = getOrderAmt(numSpools, numStock);
        shippingTotal = calcShipping(orderAmount);
        displayResults(numSpools, numStock, shippingTotal);
    }

    return 0;
}
