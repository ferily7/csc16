/*
 Problem 1: Complete the following three functions:
    1) fill_rand
    2) count_zero
    3) two_zeros
 
 There are comments in each function telling you what the function should do.
 
 DO NOT ALTER THE MAIN FUNCTION.  When you compile and run this program,
 you should get the following output:
============================================
 A program to experiment with random numbers
 Calling fill_rand ...
 Vector test1 has 100 elements.
 Calling count_zero ...
 Number of zeros in vector test2: 2
 Calling two_zeros ...
 two_zeros(test2) = 0
 two_zeros(test3) = 1
============================================
 
 Note: There should be NO OTHER OUTPUT FROM YOUR PROGRAM. In particular, there should
 be no "cout" statements in any of the functions you write.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void fill_rand(vector<int> & experiment){
    for(int i = 0; i < 100; i++){
        int r = rand() % 10;
        experiment.push_back(r);
    }
}

//Count and return the number of times zero appears in the vector.
int count_zero(vector<int> & experiment){
    int counter = 0;
    for(int i = 0; i < experiment.size(); i++){
        if(experiment[i] == 0){
            counter += 1;
        }
    }
    return counter;
}

//Return true if zero appears twice in a row in the vector; otherwise return false
bool two_zeros(vector<int> & experiment){
    bool statement = false;
    for(int i = 1; i < experiment.size(); i++){
        if(experiment[i] == experiment[i-1]){
                statement = true;
        }
    }
    return statement; 
}


int main(int argc, const char * argv[]) {
    srand(time(0)); //See the random number generator
    cout << "A program to experiment with random numbers" << endl;
    
    vector<int> test1, test2, test3;
    
    cout << "Calling fill_rand ..." << endl;
    fill_rand(test1);
    cout << "Vector test1 has " << test1.size() << " elements." << endl;
    
    test2.push_back(1);
    test2.push_back(0);
    test2.push_back(1);
    test2.push_back(0);
    test2.push_back(1);
    
    cout << "Calling count_zero ..." << endl;
    cout << "Number of zeros in vector test2: " << count_zero(test2) << endl;
    
    test3.push_back(0);
    test3.push_back(1);
    test3.push_back(0);
    test3.push_back(1);
    test3.push_back(1);
    test3.push_back(1);
    cout << "Calling two_zeros ..." << endl;
    cout << "two_zeros(test2) = " << two_zeros(test2) << endl;
    cout << "two_zeros(test3) = " << two_zeros(test3) << endl;
    
    return 0;
}
