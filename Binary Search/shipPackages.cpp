#include <bits/stdc++.h>
using namespace std;




int possible(vector<int> &weights, int capacity, int days){
	
	int requiredDays=1;
	int currentWeight=0;

	for(auto &weight: weights){

		if(currentWeight + weight > capacity){
			requiredDays ++;
			currentWeight = weight;

		}

		else currentWeight += weight;
	}

	return (requiredDays <= days);

}

int shipWithinDays(vector<int> &weights, int days){

	int low = *(max_element(weights.begin(),weights.end()) );
	int high=0;

	for(auto &elem: weights){

		high += elem;

	}

	while(high >= low){

		int mid = low + (high-low)/2;

		if(possible(weights,mid,days)) high=mid-1;
		else low=mid+1;

	}

	return low;

}

int main(){

	
	vector<int> w1 = {1,2,3,4,5,6,7,8,9,10};
	int days = 5;

	cout<< "tc1 = "<< shipWithinDays(w1,days)<<endl;
	return 0;
}
