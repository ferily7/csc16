/* Author: Farrah Lee
   Program: Weather Report */

#include <iostream>
using namespace std;

int main(){

    //Declaration of variables
    int current, high, low, speed, condition, probability;
    char direction, precipitation, form;
    double amount;

    //Asking the user for an input
    cout << "Weather input: ";
    cin >> current >> high >> low >> direction >> speed >> condition >> precipitation;

    if (precipitation == 'P'){
	cin >> probability >> form >> amount;
    }
    
    cout << "WEATHER REPORT FROM HOFSTRA WEATHER CENTER.\n";
    cout << "***********************************************\n";

    cout << "Curent Temperature: " << current << " degrees.\n";
    cout << "High: " << high << " degrees.\n";
    cout << "Low: " << low << " degrees.\n";

    if (direction == 'a'){
	cout << "The winds are from the NORTH at " << speed << " miles per hour.\n";
    }
    else if (direction == 'b'){
	cout << "The winds are from the NORTHEAST at " << speed << " miles per hour.\n";
    }
    else if (direction == 'c'){
	cout << "The winds are from the EAST at " << speed << " miles per hour.\n";
    }
    else if (direction == 'd'){
	cout << "The winds are from the SOUTHEAST at " << speed << " miles per hour.\n";
    }
    else if (direction == 'e'){
	cout << "The winds are from the SOUTH at " << speed << " miles per hour.\n";
    }
    else if (direction == 'f'){
	cout << "The winds are from the SOUTHWEST at " << speed << " miles per hour.\n";
    }
    else if (direction == 'g'){
	cout << "The winds are from the WEST at " << speed << " miles per hour.\n";
    }
    else if (direction == 'h'){
	cout << "The winds are from the NORTHWEST at " << speed << " miles per hour.\n";
    }

    if (condition == 1){
    	cout << "The skies are sunny.\n";
    }
    else if (condition == 2){
  	cout << "The skies are partly sunny.\n";   
     }
    else if (condition == 3){
     	cout << "The skies are partly cloudy.\n";
    }
    else if (condition == 4){
     	cout << "The skies are cloudy.\n";
    }
    else if(condition == 5){
     	cout << "The skies are clear!\n";
    }

   //if (precipitation == 'Y'){
       if (form == 'R'){
	  cout << "There is a " << probability << " percent chance of rain.\n";	
	  cout << "Expect " << amount << "in of rain.\n";
       }
       else if(form == 'S'){
	  cout << "There is a " << probability << "chance of snow.\n";	
	  cout << "Expect " << amount << "in of snow.\n";	
       }
    //}

    cout << "***********************************************\n";
    return 0;
}

