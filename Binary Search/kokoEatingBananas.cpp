
#include <bits/stdc++.h>
using namespace std;


long long totalHours(vector<int> piles, long long k){
	
	long long ans = 0;

	for(long long i = 0 ; i < piles.size(); i++){
		ans += ceil( (double) piles[i] / (double) k);

	}

	return ans;

}

long long BruteForce(vector<int> &piles, int h){


	long long k = *max_element(piles.begin(),piles.end());

	for(long long i=1; i<=k; i++){

		long long totalHrs = totalHours(piles,i);

		if(totalHrs > h) continue;

		else return k;
	
	}

}



long long optimized(vector<int> &piles,int h){


	int low=1,high=*(max_element(piles.begin(),piles.end()));

	while(high >= low){
		
		long long mid = low + (high-low)/2;

		long long totalHrs = totalHours(piles,mid);

		if(totalHrs<=h) high=mid-1;
		
		else low = mid+1;
	
	}

	return low;


}



int main(){

	vector<int> n1 = {3,6,7,11};
	int h1 = 8;

	cout<< "Output 1 = "<< optimized(n1,h1)<<endl;

	return 0;
}



