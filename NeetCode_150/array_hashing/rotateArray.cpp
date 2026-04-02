#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotateArr(vector<int> &arr, int d){

	vector<int> tmp(d,0);
	int n = arr.size();

	for(int i=0;i<d;i++){
		tmp[i]=arr[i];
	}

	for(int i=0;i<n-d;i++){
		arr[i] = arr[i+d];
	}

	for(int i=0;i<d;i++){
		arr[n-d+i] = tmp[i];
	}
}

void printArray(vector<int> &arr){
	for(const int &n: arr){
		cout<< n << " ";
	}
	cout<< endl;
}

int main(){

	vector<int> arr = {1,2,3,4,5};
	int d=2;
	rotateArr(arr,2);
	printArray(arr);
	
	return 0;
}
