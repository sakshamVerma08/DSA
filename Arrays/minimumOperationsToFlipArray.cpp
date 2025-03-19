#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode daily problem March 19 '25
// This problem uses Deque (Double End Queue)
// Time complexity: O(2N)
// space complexity: O(N)
int minOperations(vector<int> &nums)
{
    deque<int> flipQueue;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        while (!flipQueue.empty() && i > flipQueue.front() + 2)
        {
            flipQueue.pop_front();
        }

        if ((nums[i] + flipQueue.size()) % 2 == 0)
        {
            if (i + 2 >= nums.size())
            {
                return -1;
            }
            count++;
            flipQueue.push_back(i);
        }
    }

    return count;
}

// time complexity: O(N)
// space complexity: O(1)
int minOperations2(vector<int> &nums)
{
    int count = 0;

    for (int i = 2; i < nums.size(); i++)
    {

        if (nums[i - 2] == 0)
        {
            nums[i - 2] ^= 1;
            nums[i - 1] ^= 1;
            nums[i] ^= 1;
            count++;
        }
    }

    int sum = 0;
    for (auto &elem : nums)
    {
        sum += elem;
    }

    if (sum == nums.size())
        return count;

    return -1;
}

int minOperations3(vector<int> &nums)
{
    cout << "nada";
}
int main()
{

    vector<int> tc1 = {1, 1, 1, 1};
    vector<int> tc2 = {0, 0, 0, 0, 0};

    cout << "test case 1 : " << minOperations2(tc1) << endl;
    cout << "test case 2 : " << minOperations2(tc2) << endl;

    return 0;
}