#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time complexity: O(N^2)
// space comlexity: O(N)
int maxFrequency(vector<int> &nums, int k)
{
    map<int, int> mpp;
    int diff;
    int temp;
    for (auto &elem : nums)
    {
        temp = k;
        if (mpp.find(elem) != mpp.end())
        {
            mpp[elem]++;
            continue;
        }

        for (auto &e : nums)
        {

            if (e == elem)
            {
                mpp[e]++;
                continue;
            }

            if (e > elem)
                break;

            diff = elem - e;

            if (diff <= temp)
            {
                mpp[elem]++;
                temp -= diff;
            }

            else
                continue;
        }
    }

    int maxCnt = 0;

    for (auto &iter : mpp)
    {
        if (iter.second > maxCnt)
            maxCnt = iter.second;
    }

    return maxCnt;
}

int main()
{

    vector<int> tc1 = {1, 1, 4, 8, 13};
    int k1 = 5;

    vector<int> tc2 = {9930, 9923, 9983, 9997, 9934, 9952, 9945, 9914, 9985, 9982, 9970, 9932, 9985, 9902, 9975, 9990, 9922, 9990, 9994, 9937, 9996, 9964, 9943, 9963, 9911, 9925, 9935, 9945, 9933, 9916, 9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913, 9916, 9993, 9930, 9975, 9924, 9988, 9923, 9910, 9925, 9977, 9981, 9927, 9930, 9927, 9925, 9923, 9904, 9928, 9928, 9986, 9903, 9985, 9954, 9938, 9911, 9952, 9974, 9926, 9920, 9972, 9983, 9973, 9917, 9995, 9973, 9977, 9947, 9936, 9975, 9954, 9932, 9964, 9972, 9935, 9946, 9966};
    int k2 = 3056;

    vector<int> tc3 = {1, 4, 8, 13, 8};
    int k3 = 5;

    // cout << "tc1 : " << maxFrequency(tc1, k1) << endl;
    cout << "tc2 : " << maxFrequency(tc2, k2) << endl;
    return 0;
}