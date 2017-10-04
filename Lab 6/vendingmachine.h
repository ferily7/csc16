#include <string>
using namespace std;

class VendingMachine{

	private:
	   double deposited, total_profit;
	   int frogs, beans;
    public:
       VendingMachine(); //Constructor
       void coin(double coimDenom);
       void bill(double billDenom);
       void dispense(int candy);
       void printReport(string password);
};
