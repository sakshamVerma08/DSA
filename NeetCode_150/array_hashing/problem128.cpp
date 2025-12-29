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

int main(){

	vector<int> n1 = {100,4,200,1,3,2};
	cout<<"res = "<< longestSequence(n1)<<endl;

	return 0;

}
