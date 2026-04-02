#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &nums, int st, int end){

	int ans = INT_MIN;

	for(int i = st; i <= end; i++){
		ans = max(ans,nums[i]);
	}

	return ans;

}

vector<int> maxSlidingWindow(vector<int> &nums, int k){


	int left = 0, right = k-1;
	vector<int> ans;

	while(right < nums.size() && right - left + 1 == k){
		ans.emplace_back(findMax(nums,left,right));
		left++;
		right++;
	}

	return ans;


}


void printVec(vector<int> &nums){

	for(const int &n : nums){
		cout<< n << " ";

	}

	cout<<endl;

}


int main(){

	vector<int> tc1 = {1,3,-1,-3,5,3,6,7};
	int k1 = 3;

	vector<int> ans = maxSlidingWindow(tc1,k1);

	printVec(ans);

	return 0;
}
