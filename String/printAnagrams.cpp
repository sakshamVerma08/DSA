#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printAnagrams(vector<string> arr){
	
	if(arr.size()==1)
		cout<< arr[0]<<endl;

	for(auto &s: arr){

		sort(s.begin(),s.end());
	}


	for(auto &s: arr){

		cout<< s << " ";

	}

	cout<<endl;
}


int main(){

	vector<string> arr = {"eat", "tea","ate"};

	printAnagrams(arr);

	return 0;

}
