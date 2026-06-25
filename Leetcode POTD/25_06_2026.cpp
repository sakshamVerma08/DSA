#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(){
	}
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int tgt_count=0;
            for(int j=i;j<n;j++){
                if(nums[j] == target)
                    tgt_count++;

                if(tgt_count > 0 && tgt_count > (j-i+1)/2)
                    cnt++;
            }
        }

        return cnt;
    }

    int func(vector<int> &nums, int target){

    }
};

int main(){

	vector<int> arr;
	int target;
	cin>>target;
	cin.ignore();
	string elem;

	getline(cin, elem);
	stringstream ss(elem);

	int num;

	while(ss >> num){
		arr.push_back(num);
	}

	Solution* s = new Solution();
	cout<<"Ans = "<< s->func(arr,target)<<endl;

	return 0;

}
