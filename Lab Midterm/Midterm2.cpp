#include "Midterm.h"
#include <iostream>
#include <string>
using namespace std;

Car::Car(int yr, string m){ //Constructor
	year = yr;
	make = m;
	speed = 0;
} 

void Car::printReport(){
	cout << "Car Year: " << year << endl;
	cout << "Car Model: " << make << endl;
	cout << "Speed: " << speed << endl; 
}
void Car::accelerate(double amount){
	if(amount > 0 && speed < 60){
		speed = speed + amount;
	}
	else if(speed > 60){
		speed = 60;
	}
}
void Car::brake(){
	if(speed > 0){
		speed = speed - 5;
	}
	else if(speed < 0){
		speed = 0;
	}
}