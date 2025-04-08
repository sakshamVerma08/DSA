#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    vector<int> ans;
    unordered_map<int, int> mpp;

    for (int i = 0; i < k; i++)
    {
        mpp[nums[i]]++;
    }

    ans.push_back(calcXSum(mpp, x));

    int left = 1;
    int n = nums.size();

    while (left <= n - k)
    {
        mpp[nums[left - 1]]--;
        if (mpp[nums[left - 1]] == 0)
            mpp.erase(nums[left - 1]);

        mpp[nums[left + k - 1]]++;
        ans.push_back(calcXSum(mpp, x));
        left++;
    }

    return ans;
}

int calcXSum(unordered_map<int, int> &mpp, int x)
{
    priority_queue<pair<int, int>> pq;

    for (auto &p : mpp)
    {
        pq.push({p.second, p.first});
    }

    int sum = 0;

    for (int i = 0; i < x && !pq.empty(); i++)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        sum += (top.second * top.first);
    }

    return sum;
}

int main()
{

    return 0;
}