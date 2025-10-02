


#include <bits/stdc++.h>
using namespace std;



int squareRoot(int n){

	int low=0,high=n;
	int ans = 0;
	while(high >= low){

		long long mid = low + (high-low)/2;

		if(mid*mid<=n){
			ans=mid;
			low=mid+1;
		}


		else high = mid-1;


	}

	return ans;


}

int main(){


	int n1 = 7;
	cout<<" tc1 = "<< squareRoot(n1)<<endl;

	int n2 = 13;
	cout<< "tc2 = "<< squareRoot(n2)<<endl;

	return 0;


}





