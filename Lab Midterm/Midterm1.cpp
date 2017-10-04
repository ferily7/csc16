#include <iostream>
#include <vector>
using namespace std;

void fill(vector<int> & nums, int N);
int get(vector<int> & nums, int i, int N);
void makeChange(vector<int> & nums, int N);

int main(){
	vector<int> nums;
	int N = 8;
	fill(nums, N);
	makeChange(nums, N);

	cout << "Making change for " << N << ": ";
	cout << "Need " << nums[N] << " coins.\n";
	return 0;
}

void fill(vector<int> & nums, int N){
	for(int i = 0; i < N+1; i++){
		nums.push_back(0);
	}
}

int get(vector<int> & nums, int i, int N){
	if(i < 0)
		return N+1;
	else
		return nums[i];
}

void makeChange(vector<int> & nums, int N){
	int less1, less4, less5;

	for(int i = 1; i < N+1; i++){
		less1 = get(nums, i-1, N);
		less4 = get(nums, i-4, N);
		less5 = get(nums, i-5, N);

		if(less1 < less4 && less1 < less5)
			nums[i] = less1 + 1;
		else if(less4 < less1 && less4 < less5)
			nums[i] = less4 + 1;
		else
			nums[i] = less5 + 1;
	}
}