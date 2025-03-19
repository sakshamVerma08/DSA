#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity: O(N^2)
// space complexity: O(1)
vector<int> twoSum(vector<int> &nums, int target)
{
    int sum;
    vector<int> vec;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (sum + nums[j] == target)
            {
                vec.push_back(i);
                vec.push_back(j);
                break;
            }
        }

        if (vec.size() != 0)
            break;
    }

    return vec;
}

// Better Approach (Using hashing)
// Time complexity:
// Unorderd map: O(N)
// Worst case : O(N^2)

// Ordered Map: O(N logN)

// space complexity: O(N)

vector<int> twoSum2(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    vector<int> vec;
    int val;
    for (int i = 0; i < nums.size(); i++)
    {

        val = target - nums[i];

        if (mpp.find(val) != mpp.end())
        {
            vec.push_back(i);
            vec.push_back(mpp[val]);
            break;
        }

        mpp[nums[i]] = i;
    }

    return vec;
}

// Optimized Approach (using two pointer + sorting)
// Time complexity: O(NlogN)
// Space complexity: O(1)
vector<int> twoSum3(vector<int> &nums, int target)
{
}

void printVector(vector<int> &v)
{
    for (auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> tc1 = {3, 2, 4};
    int target1 = 6;

    vector<int> ans = twoSum2(tc1, target1);
    printVector(ans);

    return 0;
}