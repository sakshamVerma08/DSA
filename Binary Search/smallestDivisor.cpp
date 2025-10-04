#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold){

	
	int sum = 0,temp;

	for(int i = 1; i <= threshold; i++){

		for(auto &elem: nums){
			temp = ceil( (double)elem/i);
			sum += temp;

		}

		if(sum <= threshold) return i;

		else sum = 0;
	}

}

// Optimized Solutin using Binary Search
int smallestDivisor2(vector<int> &nums, int threshold){


	int low=1,high=*(max_element(nums.begin(),nums.end() ) );
	int sum,temp;

	while(high>=low){

	int mid = low + (high-low)/2;


	sum=0;
	for(auto &elem: nums){
		temp = ceil( (double)elem/mid);
		sum += temp;
	}

	if(sum <= threshold) high=mid-1;

	else low = mid+1;

	}

	return low;


}

int main(){
	

	vector<int> n1 = {1,2,5,9};
	int th1 = 6;

	cout<< "tc1 = "<< smallestDivisor2(n1,th1)<<endl;


	return 0;
}
