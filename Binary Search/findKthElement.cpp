#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE Solution

int findKthPositive(vector<int> &arr, int k){

	int cnt = 0, idx = 0, ans = -1;

	for(int i = 1; i< INT_MAX; i++){

		if(idx < arr.size() && i == arr[idx]) idx++;


		else{
		
			cnt++;

			if(cnt==k){
				ans=i;
				break;

			}


		}

	}


	return ans;


}


// OPTIMIZED SOLUTION
int findKthPositive2(vector<int> &arr, int k){

	int low = 0, high = arr.size()-1;

	while(high >= low){

		int mid = low + (high-low)/2;

		int missing = arr[mid] - (mid+1);

		if(missing < k) low = mid + 1;

		else high = mid-1;

	}

	return high + 1 + k;
}

int main(){


	vector<int> arr = {1,2,3,4};
	int k1 = 2;

	cout<<"tc1 = "<<findKthPositive2(arr,k1)<<endl;
	return 0;

}
