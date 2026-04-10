#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        unordered_map<int,vector<int>> mpp; // Use of this hashmap is to map the elements with a vector of the positions where they are in the input array. This can be built in O(n) time.
        int n = arr.size();

        for(int i = 0; i < arr.size();i++){
            // looping from 0 to n-1 (inclusive).
            mpp[arr[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto it = mpp.begin();it!=mpp.end();it++){

            if(it->second.size()>=3){
                vector<int> &v = it->second;
                
                // We are not guaranteed that the first 3 indices will give the minimal result. So we will have to check each good tuple from the set of index values(vector) in the map.
                // for this implementation, I will take the value of a to be at ith index in the vector of indices, and check if i can pick the two indices at next two positions, that is at i+1 and i+2. (i+2<n) checks this only.
                // If i can, then i will pick and calculat distance, and update the answer accordingly.
                // But we cannot stop here, so we move to next ith index, so that we can pick a new value for a , and check the next good tuple.
                for(int i = 0; i < v.size();i++){
                    int a = v[i];
                    if(i+2 < v.size()){
                        // for a parcitular i, looping two indices ahead of that index position. 
                        // So in total, looping from i+1 to (i+1)+1 (inclusive).
                        int b = v[i+1];
                        int c = v[i+2];
                        int dist = abs(a-b) + abs(b-c) + abs(c-a);
                        ans = min(dist,ans);
                    }
                }
            }
        }

        return ans==INT_MAX? -1: ans;
    }
};

int main(){

	Solution *s = new Solution();
	vector<int> arr = {1,2,3,1,8,7,1,8,8,3};
	int tc1 = s->minimumDistance(arr);
	cout<< "tc1 = "<< tc1 << endl;

	return 0;

}
