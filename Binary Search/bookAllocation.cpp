#include <bits/stdc++.h>
using namespace std;

// Brute force (Linear Search): O(sum(arr) - max_elem) * n (time commplexity)

bool helper1(vector<int> &arr, int pages , int m){

	int currentCount = 0, stCount = 1;


	for(int i = 0; i< arr.size(); i++){



		if(currentCount + arr[i] <= pages) currentCount += arr[i];

		else{

			stCount++;
			currentCount = arr[i];
		}
	}



	if(stCount <= m) return true;
	return false;


}


int findPages(vector<int> &arr, int n, int m){
	
	if(m > arr.size()) return -1;

	int low = *(max_element(arr.begin(), arr.end()));

	int high = 0;

	for(auto &pages: arr){

		high += pages;

	}




	for(int i = low; i<= high; i++){

		if(helper1(arr,i,m)) return i;
	}
	
	
	return -1;
	

}



int helper2(vector<int> arr, int pages){


	int stCount = 1, currentPages = 0;

	for(int i = 0; i< arr.size(); i++){


		if(arr[i] + currentPages <= pages) currentPages += arr[i];

		else{

			stCount++;
			currentPages=arr[i];
		}
	}


	return stCount;
}

// Optimized Solution (Binary Search)
int findPages2(vector<int> &arr, int n, int m){
	
	if(m>arr.size()) return -1;

	int low = *(max_element(arr.begin(), arr.end()));
	int high = 0;

	for(auto&elem : arr){
		high += elem;

	}



	while(high>=low){


		int mid = low + (high-low)/2;


		if(helper2(arr,mid) <= m) high = mid -1;

		else low = mid + 1;
	}


	return low;
}



int main(){

	vector<int> arr1 = {12,34,67,90};
	int m = 2;

	cout<< "tc1 = "<< findPages2(arr1, arr1.size(), m)<<endl;
	return 0;


}
