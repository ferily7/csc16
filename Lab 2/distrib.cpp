/* Author: Farrah Lee
Program: Counting how many times the average was in a range */

#include <iostream>
using namespace std;

int main(){

	//Declaration of variables
	int seed, r;
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, 
	count6 = 0, count7 = 0, count8 = 0, count9 = 0, count10 = 0;
	seed = time(0);
	srand(seed);

	for(int i=0; i<100; i++){
		int sum = 0, average = 0;
		//This for loop sums up 10 random numbers
		for(int j=0; j<10; j++){
			r = rand() % 100;
			sum = sum + r;
		}
		//This takes the average of the sum
		average = sum / 10;
		cout << "The average is: " << average << endl;

		//This if-else if statement checks to see which range the average number is in
		if(average < 10){
			count1++;
		}
		else if(average < 20){
			count2++;
		}
		else if(average < 30){
			count3++;
		}
		else if(average < 40){
			count4++;
		}
		else if(average < 50){
			count5++;
		}
		else if(average < 60){
			count6++;
		}
		else if(average < 70){
			count7++;
		}
		else if(average < 80){
			count8++;
		}
		else if(average < 90){
			count9++;
		}
		else{
			count10++;
		}
	}

 	cout << "0-9: " << count1 << endl;
 	cout << "10-19: " << count2 << endl;
 	cout << "20-29: " << count3 << endl;
	cout<< "30-39: " << count4 << endl;
	cout <<  "40-49: " << count5 << endl;
	cout <<  "50-59: " << count6 << endl;
 	cout << "60-69: " << count7 << endl;
 	cout <<  "70-79: " << count8 << endl; 
 	cout << "80-89: " << count9 << endl; 
 	cout << "90-99: " << count10 << endl;

}