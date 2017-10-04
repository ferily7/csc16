/*
 Write a program to simulate the use of cell phone minutes on a prepaid plan.
 According to the plan, refills may only be made in whole dollar amounts. Each
 dollar gives the user 10 minutes of talk time.
 
 NOTE: This is similar to the BankAccount class on the Midterm Exam.
 */

#include <iostream>
#include <vector>
using namespace std;

class Prepaid{
private:
    int balance;
    vector<int> transactions;
    
public:
    Prepaid(int initial_dollars);
    void refill(int dollar_amount);
    void use_minutes(int minutes);
    int longest_call();
    void report();
    
};


Prepaid::Prepaid(int initial_dollars){
    balance = initial_dollars * 10;
}

void Prepaid::refill(int dollar_amount){
    balance = dollar_amount * 10;
    transactions.push_back(balance);  
}

void Prepaid::use_minutes(int minutes){
    if(minutes > balance){
      balance = 0;
      cout << "Call interrupted due to zero balance" << endl;
    }
    else{
      balance = balance - minutes;
    }
    transactions.push_back(minutes*-1);
}

int Prepaid::longest_call(){
    int longestCall;
    for(int i = 1; i < transactions.size(); i++){
      if(transactions[i] > transactions[i-1]){
        longestCall = transactions[i];
      }
      else if(transactions[i] < transactions[i-1]){
        longestCall = transactions[i-1];
      }
    }
    return longestCall; 
}

void Prepaid::report(){
    //This function is complete, don't mess with it!
    cout << "\n\nMinutes remaining: " << balance << endl;
    cout << "# transactions: " << transactions.size() << endl << endl << endl;
}

int main() {
    //Don't mess with the main function!
    Prepaid my_phone(10);
    int choice;
    
    my_phone.report(); //This should show a balance of 100 minutes with 0 transactions
    cout << "\n\n1. Use minutes\n"
    "2. Refill\n"
    "3. Report\n"
    "4. Longest call length\n"
    "5. Quit\n"
    "Choice: ";
    cin >> choice;
    while (choice != 5) {
        if ( choice == 1){
            int minutes;
            cout << "How many minutes? ";
            cin >> minutes;
            my_phone.use_minutes(minutes);
        }
        else if (choice == 2){
            int dollars;
            cout << "How many dollars? ";
            cin >> dollars;
            my_phone.refill(dollars);
        }
        else if ( choice == 3){
            my_phone.report();
        }
        else if (choice == 4){
            cout << "Longest call length: " << my_phone.longest_call() << " minutes." << endl;
        }
        cout << "\n\n1. Use minutes\n"
        "2. Refill\n"
        "3. Report\n"
        "4. Longest call length\n"
        "5. Quit\n"
        "Choice: ";
        cin >> choice;
    }
    my_phone.report();
}
