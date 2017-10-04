#include <iostream>
#include <vector>
using namespace std;

void gen(vector<int> & nums, int N);
int place(int value, vector<int> & tops);
void longest(vector<int> & nums, int N);

int main(){
	vector<int> nums;
	gen(nums, 10);
	longest(nums, 10);
	return 0;
}

void gen(vector<int> & nums, int N){
	int choice;
	for(int i = 0; i < N; i++){
		cout << "Enter a number: ";
		cin >> choice;
		nums.push_back(choice);
	}
}

int place(int value, vector<int> & tops){
	for(int i = 0; i < tops.size(); i++){
		if(value < tops[i])
			return i;
	}
	return -1;
}

void longest(vector<int> & nums, int N){
	vector<int> tops;
	int index;

	for(int i = 0; i < N; i++){
		index = place(nums[i], tops);

		if(index == -1)
			tops.push_back(nums[i]);
		else
			tops[index] = nums[i];
	}

	cout << tops.size() << endl;
}
