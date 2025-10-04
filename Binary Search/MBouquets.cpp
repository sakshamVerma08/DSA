


#include <bits/stdc++.h>
using namespace std;

//Brute Force Solution with TC = O((max-min element + 1) * n)




int possible(vector<int> &bloomDays, int day, int m, int k){

	int cnt = 0, ans = 0;

	for(int i = 0; i < bloomDays.size(); i++){

		if(bloomDays[i] <= day) cnt++;


		else{
			ans += cnt/k;
			cnt = 0;
		}

	}


	ans+= cnt/k;

	if(ans >= m) return 1;

	return 0;


}


int minDays(vector<int> &bloomDays, int m, int k){

	
	if(bloomDays.size() < m * k) return -1;// not enough flowers condition.

	int min = *(min_element(bloomDays.begin(),bloomDays.end()));
	int max = *(max_element(bloomDays.begin(),bloomDays.end()));

	for(long long i = min; i<=max;i++){

		if(possible(bloomDays, i, m , k) == 1) return i;


	}



}

// OPTIMIZED PART USING BINARY SEARCH
int minDays2(vector<int> &bloomDays, int m, int k){

	
	if(bloomDays.size()< m * k) return -1;



	int low = *(min_element(bloomDays.begin(),bloomDays.end()));
	int high = *(max_element(bloomDays.begin(),bloomDays.end()));

	while(high >= low){

		long long mid = low + (high-low)/2;


		if(possible(bloomDays,mid,m,k) == 1) high = mid-1;

		else low = mid + 1; 


	}

	return low;

}

int main(){


	vector<int> case1 = {10,3,1,10,2};
	int m = 3, k=2;

	cout<< " case 1 = "<< minDays2(case1,m,k)<<endl;


	vector<int> case2 = {10,3,1,10,2};
	int m2 = 3, k2 = 1;


	cout<< "case 2 = "<< minDays2(case2,m2,k2)<<endl;

	return 0;}
