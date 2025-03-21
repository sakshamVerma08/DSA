#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using sorting
// time complexity: O(N logN)
// space complexity: O(1)
int majorityElement(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
// time complexity: O(N)
// space complexity: O(N)
int majorityElement2(vector<int> &nums)
{
    unordered_map<int, int> frequencies;

    for (auto &elem : nums)
    {
        frequencies[elem]++;
    }

    int ans;
    int temp = nums.size() / 2;

    for (auto &pair : frequencies)
    {
        if (pair.second > temp)
        {
            temp = pair.second;
            ans = pair.first;
        }
    }

    return ans;
}

// optimized approach
// time complexity : O(N)
// space complexity: O(1)
// Using Moore's Voting Algorithm
int majorityElement3(vector<int> &nums)
{

    int curr = nums[0];
    int cnt = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            curr = nums[i];
            cnt = 1;
            continue;
        }

        if (nums[i] == curr)
            cnt++;

        else
            cnt--;
    }

    return curr;
}

int main()
{
    vector<int> tc1 = {3, 2, 3};
    cout << "tc1 = " << majorityElement4(tc1) << endl;
    vector<int> tc2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "tc2 = " << majorityElement4(tc2) << endl;

    return 0;
}
