#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE METHOD O(high-low+1) * n
 bool helper(vector<int> &nums, int maxSum, int k){

        int subArrCnt = 1, currentSum = 0;

        for(int i= 0; i< nums.size();i++){


            if(currentSum + nums[i] <= maxSum) currentSum+= nums[i];

            else{
                subArrCnt ++;
                currentSum= nums[i];
            }
        }


        if(subArrCnt<=k) return true;
        return false;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *(max_element(nums.begin(),nums.end()));
        int high = 0;

        for(auto &elem: nums){
            high += elem;
        }


        for(int i = low; i<= high; i++){

            if(helper(nums,i,k)) return i;


        }


        return -1;
    }


// Optimized Solution (Binary Search) O(log(high-low+1) *n )

 bool helper2(vector<int> &nums, int maxSum, int k){

        int subArrCnt = 1, currentSum = 0;

        for(int i= 0; i< nums.size();i++){


            if(currentSum + nums[i] <= maxSum) currentSum+= nums[i];

            else{
                subArrCnt ++;
                currentSum= nums[i];
            }
        }


        if(subArrCnt<=k) return true;
        return false;
    }


    int splitArray2(vector<int>& nums, int k) {
        int low = *(max_element(nums.begin(),nums.end()));
        int high = 0;

        for(auto &elem: nums){
            high += elem;
        }


	while(high>=low){
		int mid = low + (high-low)/2;

		if(helper2(nums,mid,k)) high = mid -1;

		else low = mid + 1;

        }


        return low;
    }



int main(){

	vector<int> arr = {7,2,5,10,8};
	int k1 = 2;

	cout<< "tc1 = "<< splitArray2(arr,k1)<<endl;

	return 0;
}
