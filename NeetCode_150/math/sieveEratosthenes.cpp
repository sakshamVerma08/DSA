#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> sieveEratosthenes(int n){

	vector<int> blackBox(n+1,1);



}

void printVec(vector<int> &arr){
	for(int i=2;i<arr.size();i++){
		if(arr[i] != 0)
			cout<< i << " ";
	}
	cout << endl;
}

int main(){

	int n = 100;
	vector<int> primeArr = sieveEratosthenes(n);
	printVec(primeArr);

	return 0;
}
