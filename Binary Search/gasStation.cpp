#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution
// Will give a TLE error. See the Optimized approach.
long double minimizeMaxDistance(vector<int> &arr, int k){
	int n = arr.size();

	vector<int> howMany(n-1,0);

	for(int gasStations = 0; gasStations <= k; gasStations++){

		long double maxSection = -1;

		int maxInd = -1;

		for(int i = 0; i< n-1; i++){


			long double diff = arr[i+1] - arr[i];

			long double sectionLength = diff/ (long double) howMany[i] + 1;

			if(sectionLength > maxSection){


				maxSection = sectionLength;
				maxInd = i;
			}
		}



		howMany[maxInd] ++;

	};


	long double maxAns = -1;

	for(int i =0; i< n-1; i++){

		long double diff = (arr[i+1] - arr[i]);
		long double sectionLength = diff/ (long double) (howMany[i] + 1);
		maxAns = max(sectionLength,maxAns);
	}


	return maxAns;

}


int main(){

	vector<int> tc1 = {1,4,6,10,11};
	int k1 = 1;

	cout<< "tc1 = "<< minimizeMaxDistance(tc1,k1)<<endl;


	return 0;

}
