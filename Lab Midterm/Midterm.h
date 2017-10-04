#include <string>
using namespace std;

class Car{
	private:
		int year;
		string make;
		double speed;

	public:
		Car(int yr, string m); //Constructor
		void printReport();
		void accelerate(double amount);
		void brake();
};