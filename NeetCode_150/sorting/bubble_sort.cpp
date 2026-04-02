#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
	int n = arr.size();
 	for(int i = n-1; i >= 0; i--){

		for(int j = 0; j < n-1;j++){

			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

		}

	}

	return;

}

int main(){

	vector<int> v = {50,30,10,20,1};
	bubbleSort(v);
	for(const int &n:v){
		cout<<n<<" ";
	}

	cout<<endl;
	return 0;
}
