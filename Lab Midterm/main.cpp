#include "Midterm.h"
#include <iostream>
using namespace std;

int main(){
	Car speedy(2016, "von Prechtl");

	cout << "Accelerating for 5 seconds.\n";
	for(int i = 1; i <= 5; i++){
		speedy.accelerate(i*3.0);
	}

	cout << "Accelerating for 5 more seconds.\n";
	for(int i = 6; i <= 10; i++){
		speedy.accelerate(i*3.0);
	}
	
	cout << "Braking for 10 seconds.\n";
	for(int i = 1; i <= 10; i++){
		speedy.brake();
	}

	speedy.printReport();

	return 0;

}