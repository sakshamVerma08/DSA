#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		using ll = long long;
		ll MAX=sqrt(LLONG_MAX);
		int maximumLength(vector<int>&nums){
			int ans=0;
			int n=nums.size();
			unordered_map<ll,int>mpp;
			for(inti=0;i<n;i++){
				mpp[nums[i]]++;
			}

			for(auto it=mpp.begin();it!=mpp.end();it++){
				ll elem = it->first;
				if(elem==1){
					auto temp = mpp[1];
					ans=(temp%2==0)/? max(ans,temp-1): max(ans,temp);
					continue;
				}

				int len=0;
				ll curr=elem;

				while(curr<=MAX && mpp.count(curr) && mpp[curr]>=2){
					len+=2;
					curr*=curr;
				}

				len = len+ ((mpp.count(curr)==1)? 1 : -1);
				ans=max(ans,len);
		}
			return ans;

};


auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}();


int main(){

}
