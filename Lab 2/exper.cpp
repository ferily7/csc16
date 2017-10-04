/* Author: Farrah Lee
Program: Averaging Random Numbers */

#include <iostream>
using namespace std;

int main(){

	//Declaration of variables
	int sum = 0, average = 0, seed, r;
	seed = time(0);
	srand(seed);

	//This for loop sums up 10 random numbers
	for(int i=0; i<10; i++){
		r = rand() % 100;
		cout << r << endl;
		sum = sum + r;
		cout << sum << endl;
	}

	//This is taking the average of the sum and displaying it
	average = sum / 10;
	cout << "The average is: " << average << endl;
}