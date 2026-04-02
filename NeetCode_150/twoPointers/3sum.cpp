#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int target)
{

	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;

	for (int i = 0; i < n - 2; i++)
	{

		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		int &n1 = nums[i];

		for (int j = i + 1; j < n - 1; j++)
		{

			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			int &n2 = nums[j];

			for (int k = j + 1; k < n; k++)
			{

				if (k > j + 1 && nums[k] == nums[k - 1])
					continue;

				if (n1 + n2 + nums[k] == target)
					res.push_back(vector<int>{n1, n2, nums[k]});
			}
		}
	}

	return res;
}

void printResult(vector<vector<int>> &res)
{

	cout << "Printing result..." << endl;

	for (auto &vec : res)
	{

		for (auto &n : vec)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	cout << endl;
}
int main()
{

	vector<int> nums1 = {0, 1, 2, 3, 4, 45, 2, 0};
	int t1 = 47;

	auto res = threeSum(nums1, t1);
	printResult(res);

	return 0;
}
