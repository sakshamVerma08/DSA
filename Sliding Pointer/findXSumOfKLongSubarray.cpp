#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Uses Unordered map and Priority Queue. The calculateXSum is required for findXSum.
// time complexity: O(N) + O(N* k log k)
// space complexity : O(2k)
vector<int> findXSum(vector<int> &nums, int k, int x)
{
    unordered_map<int, int> mpp;
    vector<int> answer;

    for (int i = 0; i < k; i++)
    {
        mpp[nums[i]]++;
    }

    answer.push_back(calculateXSum(mpp, x));

    // Starting to slide the window

    int n = nums.size();
    for (int i = 1; i <= n - k; i++)
    {

        mpp[nums[i - 1]]--;

        if (mpp[nums[i - 1]] == 0)
            mpp.erase(nums[i - 1]);

        mpp[nums[i + k - 1]]++;

        // Adding the x-sum of current window to the answer vector
        answer.push_back(calculateXSum(mpp, x));
    }

    return answer;
}

int calculateXSum(const unordered_map<int, int> &frequencies, int x)
{

    priority_queue<pair<int, int>> pq; // taking a priority queue to get elements efficiently from the map

    for (auto &elem : frequencies)
    {
        pq.push({elem.second, elem.first});
    }

    int sum = 0;
    pair<int, int> elem;
    for (int i = 0; i < x && !pq.empty(); i++)
    {
        elem = pq.top();
        pq.pop();
        sum += (elem.second * elem.first);
    }

    return sum;
}

void printVec(vector<int> &vec)
{
    for (auto &elem : vec)
    {
        cout << elem << " ";
    }

    cout << endl;
}
int main()
{

    vector<int> tc1 = {1, 1, 3, 4, 4, 2, 3, 8, 4, 2, 3};
    vector<int> ans1 = findXSum(tc1, 4, 3);

    return 0;
}