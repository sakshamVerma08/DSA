



#include <bits/stdc++.h>
using namespace std;


int func(int n, int m, int mid){

	long long ans = 1;

	for(int x=1; x<=n; x++){

		ans *= mid;

		if(ans > m) return 2;

	}

	if(ans==m) return 1;

	return 0;

}


int NthRoot(int n, int m){

	int low=1,high=m;

	while(high>=low){

		long long mid = low + (high-low)/2;

		if(func(n,m,mid) == 1) return mid;

		else if (func(n,m,mid) == 0) low = mid+1;

		else high=mid-1;

	}


	return -1;


}

int main(){


	int m = 27;
	int n = 3;

	cout<<" tc1 = "<< NthRoot(n,m)<<endl;


	return 0;

}

