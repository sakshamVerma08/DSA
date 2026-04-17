#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution{
		
	public:
		Solution(){
		}

		int minMirrorPairDistance(vector<int>&arr){

			unordered_map<int,int> mpp;
			int n = arr.size();
			int ans = INT_MAX;

			for(int i = 0; i < n; i++){
				// looping from 0 to n-1 (inclusive).
				if(mpp.find(arr[i]) != mpp.end())
					ans = min(ans, abs(mpp[arr[i]] - i));

				string s = to_string(arr[i]);
				reverse(s.begin(),s.end());
				int n = stoi(s);
				mpp[n] = i;
			}

			return ans == INT_MAX? -1 : ans;

		}


};

int main(){

	Solution* s = new Solution();
	vector<int> arr = {12,13,14,15,21};
	vector<int> arr2 = {12,13,14,15,16};

	cout<<"ans1 = "<< s->minMirrorPairDistance(arr)<<endl;
	cout<<"ans2 = "<< s->minMirrorPairDistance(arr2)<<endl;
	return 0;
}