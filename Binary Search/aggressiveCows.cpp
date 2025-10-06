#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int dist, int k)
{

	int cowCount = 1, lastCow = stalls[0];

	for (int i = 1; i < stalls.size(); i++)
	{

		if (stalls[i] - lastCow >= dist)
		{
			cowCount++;
			lastCow = stalls[i];
		}
	}

	if (cowCount >= k)
		return true;
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
	sort(stalls.begin(), stalls.end());

	int n = stalls.size();

	int low = 1, high = stalls[n - 1] - stalls[0];

	while (high >= low)
	{

		long long mid = low + (high - low) / 2;

		if (isPossible(stalls, mid, k))
			low = mid + 1;

		else
			high = mid - 1;
	}

	return high;
}

int main()
{

	int k1 = 2;
	vector<int> stalls = {1, 2, 3};

	cout << "tc1 = " << aggressiveCows(stalls, k1) << endl;
	return 0;
}