#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int> &arr){

	map<int,vector<int>> mpp;
	sort(arr.begin(),arr.end());

	for(int i = 0; i < arr.size(); i++){

	int count = brian_kernighan(arr[i]);

	mpp[count].emplace_back(n);

	}

	int i = 0;

	for(auto &p : mpp){
		for(auto &x : p.second){
			arr[i] = x;
			i++;
		}
	}

	return arr;


}

void printVec(vector<int> &vec){

	for(const int &n : vec){
		cout<<n << " ";
	}

	cout<<endl;

}


int main(){

	vector<int> arr = {1e4,1e4, 2, 8, 13, 15, 17};
	vector<int> ans = sortByBits(arr);
	printVec(ans);

	return 0;

}
