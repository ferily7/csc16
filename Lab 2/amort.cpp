/* Author: Farrah Lee
Program: Loan Amortization Table */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

	//Declarations of variables
	double loan_amt, APR, years, monthly_interest, monthly_payment;
	int numb_of_months;

	//Asking the user for an input
	cout << "Loan amount? ";
	cin >> loan_amt;
	cout << "Annual Percentage Rate? ";
	cin >> APR;
	cout << "Years? ";
	cin >> years;

	//Sets the decimal place to the hundredth place
	cout << fixed << showpoint << setprecision(2);

	//Displays the amount, APR and year
	cout << "Amount: " << loan_amt << endl;
	cout << "APR: " << APR << "%" << endl;
	cout << "Years: " << years << endl;

	//Converts years to months
	numb_of_months = years * 12;
	//Calculates the monthly interest rate
	monthly_interest = APR / (12 * 100);

	//This calculates the monthly payment
	monthly_payment = (loan_amt * monthly_interest / (1- pow((1+monthly_interest), -numb_of_months)));
	cout << "Monthly Payment: " << monthly_payment << endl;

	//Declaration of variables
	double new_balance = loan_amt, 
		   cumm_interest = 0, 
		   paid_to_date = 0, 
		   payment_numb = 0, 
		   interest_paid = 0, 
		   principal_paid = 0;
	
	//Aligns the text to make it look like a table
	cout << setw(10) << "Payment" << setw(10) << "Interest" << setw(10) << "Principal" << setw(10) << "Cummulative" << setw(10) << "Total paid" << setw(10) << "New Balance" << endl;
 	cout << setw(10) << "Number" << setw(10) << "Paid" << setw(10) << "Paid" << setw(10) << "Interest" << setw(10) << "to date" << setw(10) << "Due" << endl;		

 	//This makes the loan amortization table with the for loop
	for(int i=0; i<12;i++){

		//Calculations for the table
		payment_numb = payment_numb + 1;
		interest_paid = new_balance * monthly_interest;
		principal_paid = monthly_payment - interest_paid;
		cumm_interest = cumm_interest + interest_paid;
		paid_to_date = paid_to_date + monthly_payment;
		new_balance = new_balance - principal_paid;

		//Displays all the numbers for the table
		cout << setw(10) << payment_numb << setw(10) << interest_paid << setw(10) << principal_paid << setw(10) << cumm_interest << setw(10) << paid_to_date << setw(10) << new_balance << endl;
 
	}
}