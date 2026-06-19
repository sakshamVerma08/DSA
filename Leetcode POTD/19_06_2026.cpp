#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

Solution(){

}
    int largestAltitude(vector<int>& arr) {
        vector<int> prefixSum;
        prefixSum.push_back(arr[0]);

        for(int i = 1; i < arr.size(); i++){


            prefixSum.push_back(prefixSum[i-1] + arr[i]);
        	
	}

	prefixSum.push_back(0);
        auto max_it =  std::max_element(prefixSum.begin(),prefixSum.end());
        return *(max_it);
    }
};


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	Solution* s = new Solution();

	cout<<"Ans = "<< s->largestAltitude(arr)<<endl;

	return 0;

}
