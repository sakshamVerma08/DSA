#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSequence(vector<int> nums){
  if(nums.size()==0)
            return 0;

        
        unordered_set<int> s(nums.begin(),nums.end());

        int res = 0;

        for(auto &val: s){

            int streak = 0;

            if(s.find(val-1) != s.end())// This means that the current elements appears at the middle of a sequence.
            // It's not at the start of the sequence
                continue;

            else{
                int curr = val;

                while(s.find(curr) != s.end()){
                    streak++;
                    curr++;
                }

                res = max(res,streak);
            }
        }

        return res;
}

int longestSequence2(vector<int> nums){


	if(nums.size()==0)
		return 0;

	sort(nums.begin(),nums.end());

	int i = 0, curr = nums[0], streak=0, res=0;


	while(i<nums.size()){


		if(curr != nums[i]){
			streak=0;
			curr=nums[i];
		}

		
		while(i<nums.size() && nums[i] == curr){
			i++;

		}

		streak++;
		curr++;
		res=max(res,streak);
	}


	return res;

}
int main(){

	vector<int> n1 = {100,4,200,1,3,2};
	cout<<"res = "<< longestSequence2(n1)<<endl;
	
	vector<int> n2 = {2,20,4,10,3,4,5};
	cout<<"res2 = "<< longestSequence2(n2)<<endl;


	return 0;

}
