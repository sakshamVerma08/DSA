#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(){}
    vector<int> leftRightDifference(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        leftSum[0]=0;

        for(int i = 1; i < n; i++){
            // looping from 1 to n-1.
            leftSum[i] = arr[i-1] + leftSum[i-1];
        }

        rightSum[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            // looping from [n-2, 0] in left <- right direction.
            rightSum[i] = rightSum[i+1] + arr[i+1];
        }

        vector<int> ans(n,0);

        for(int i = 0; i < n; i++){
            // looping from 0 to n-1.
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};

int main(){

	vector<int> arr;

	string elem;
	getline(cin,elem);
	stringstream ss(elem);

	int num;
	while(ss>>num){
		arr.push_back(num);
	}

	Solution* s = new Solution();
	auto ans = s->leftRightDifference(arr);
	for(const int &n: ans){
		cout<< n << ", ";
	}

	return 0;

}
