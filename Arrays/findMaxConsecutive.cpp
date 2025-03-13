#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxElem(vector<int> &a)
{
    int max = -1;

    for (auto &elem : a)
    {
        if (elem > max)
            max = elem;
    }
    return max;
}

// brute force approach
// time complexity: O(N)
// space complexity : O(N)
int findMaxConsecutiveOnes(vector<int> &nums)
{

    int cnt = 0;
    vector<int> counts;
    for (auto &elem : nums)
    {
        if (elem == 0)
        {
            counts.push_back(cnt);
            cnt = 0;
            continue;
        }

        cnt++;
    }

    if (cnt != 0)
        counts.push_back(cnt);

    return maxElem(counts);
}

int findMaxConsecutiveOnes2(vector<int> &nums)
{
    long cnt = 0;
    long maxCnt = 0;

    for (auto &elem : nums)
    {
        if (elem == 0)
        {
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                cnt = 0;
                continue;
            }
            else
            {
                cnt = 0;
                continue;
            }
        }

        cnt++;
    }

    maxCnt = max(cnt, maxCnt);
    return maxCnt;
}

int main()
{

    vector<int> tc1(10e5, 1);

    cout << "TC 1 : " << findMaxConsecutiveOnes(tc1) << endl;

    return 0;
}