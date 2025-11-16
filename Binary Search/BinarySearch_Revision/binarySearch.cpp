#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target){

	
	int low = 0, high = arr.size()-1;


	while(high >= low){

		int mid = low + (high-low)/2;

		if(arr[mid] == target) return mid;

		else if (target > arr[mid]) low = mid + 1;

		else high = mid -1;


	}



	return -1;


}



int main(){


	vector<int> arr1 = {1,2,3,5,6};
	int t1 = 6;

	cout<< binarySearch(arr1,t1)<<endl;

	return 0;

}
