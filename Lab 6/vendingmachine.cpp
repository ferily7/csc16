#include "vendingmachine.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void VendingMachine::coin(double coinValue){

    cout << fixed << showpoint << setprecision(2);
    if(coinValue == 5){
        deposited += .05;
    }
    else if(coinValue == 10){
        deposited += .10;
    }
    else if(coinValue == 25){
        deposited += .25;
    }
    else{
        cout << "Sorry, that is not an accepted coin.\n";   
    }
    cout << "Total deposited: " << deposited << endl; 
}

void VendingMachine::bill(double billValue){

    cout << fixed << showpoint << setprecision(2);
    if(billValue == 1 || billValue == 5){
        deposited += billValue;
        cout << "Total deposited: " << deposited <<endl; 
    }
    else{
        cout << "Sorry, that is not an accepted bill.\n";   
    }
}

void VendingMachine::dispense(int candy){

    if(candy == 1){
        if(deposited == 1){
            cout << "Here is your Chocolate Frog candy!\n" << "Change: " << deposited << endl;
        }
        else if(deposited < 1){
            cout << "Please deposit at least $1.00 for the Chocolate Frog..." << endl;
        }
        else{	   
            deposited = deposited - 1;
            cout << "Here is your Chocolate Frog candy!\n" << "Change: " << deposited << endl;   
        }
        frogs += 1;
        total_profit += 1;
    }
    else{
        if(deposited == 1.25){
            cout << "Here is your Every Flavour Bean candy!\n" << "Change: " << deposited << endl;
        }
        else if(deposited < 1.25){
            cout << "Please deposit at least $1.25 for the Every Flavour Bean..." << endl;
        }
        else{	   
            deposited = deposited - 1.25;
            cout << "Here is your Every Flavour Bean candy!\n" << "Change: " << deposited << endl;   
        }        
        beans += 1;
        total_profit += 1.25;
    }
}

void VendingMachine::printReport(string pass){
    
    if(pass == "Alohomora" || pass == "alohomora"){
        cout << "Sales Report:\n" 
        << "Number of Chocolate Frogs sold: " << frogs << endl
        << "Number of Every Flavour Beans sold: " << beans << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "Total take: " << total_profit << endl
        << "End Report" << endl;
    }
    else{
        cout << "You have entered the wrong password. Please try again." << endl;
    }
}

VendingMachine::VendingMachine(){

    frogs = 0;
    beans = 0;
    deposited = 0;
    total_profit = 0;
}
