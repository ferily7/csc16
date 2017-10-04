#include <iostream>
#include <string>
#include "vendingmachine.h"
using namespace std;


int main(){

  VendingMachine vending;
  int choice;
  cout << "Please make a selection:\n"
    << "Press 1 and ENTER to insert a coin\n"
    << "Press 2 and ENTER to insert a bill\n"
    << "Press 3 and ENTER to receive a candy\n"
    << "Press 4 and ENTER to view sales report" << endl;
  cin >> choice;

  double denom;
  int candy;
  string password;
  bool state = true;

  while(state != false){
    switch(choice){
      case 1:
        cout << "Enter coin denomination(5, 10 or 25): ";
        cin >> denom;
        vending.coin(denom);
      break;
      case 2:
        cout << "Enter bill denomination(1 or 5): ";
        cin >> denom;
        vending.bill(denom);
      break; 
      case 3:
        cout << "Enter treat choice(1 for Choco Frog, 2 for Every Flavour Bean): ";
        cin >> candy;
        vending.dispense(candy);
      break;
      case 4:
        cout << "Password: ";
        cin >> password;
        vending.printReport(password); 
      break;
    }

    cout << "Please make a selection:\n"
        << "Press 1 and ENTER to insert a coin\n"
        << "Press 2 and ENTER to insert a bill\n"
        << "Press 3 and ENTER to receive a candy\n"
        << "Press 4 and ENTER to view sales report" << endl;
    cin >> choice;
  }
}
