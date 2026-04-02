#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string &s1, string &s2){

	if(s1.size() > s2.size())
		return 0;

	unordered_map<char,int> mpp1,mpp2;

	for(int i = 0; i < s1.size(); i++){

		mpp1[s1[i]]++;
		mpp2[s2[i]]++;

	}


	if(mpp1 == mpp2)
		return true;

	int i = 0, j = s1.size();

	for(j; j < s2.size(); j++){

		
		mpp2[s2[j]]++;

		mpp2[s2[i]]--;

		if(mpp2[s2[i]] == 0)
			mpp2.erase(s2[i]);

		
		if(mpp1 == mpp2)
			return true;

		
		i++;
	}
	
	return false;

}

int main(){

	string s1 = "ab";
	string s2 = "eidbaooo";
	
	string s3 = "aabbccddeeff";
	string s4 = "zzxyyppqqrrssttaabbccddeeff";
	if(checkInclusion(s3,s4))
		cout<<"s2 contains a Permutation of s1"<<endl;

	else
		cout<<"s2 doesn't contain a Permutation of s1"<<endl;



	return 0;
}
