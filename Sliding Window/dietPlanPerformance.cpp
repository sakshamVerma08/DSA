#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Sliding window approach
// time complexity: O(n)
// space complexity: O(1)
int dietPerformance(vector<int> &calories, int k, int upper, int lower)
{
    int n = calories.size();
    int start = 0, end = k - 1;

    int pts = 0, sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += calories[i];
    }

    if (sum > upper)
        pts++;

    else if (sum < lower)
        pts--;

    while (end < n - 1)
    {
        sum -= calories[start];
        sum += calories[end + 1];
        start++;
        end++;

        if (sum > upper)
            pts++;

        else if (sum < lower)
            pts--;
    }

    return pts;
}

int main()
{

    vector<int> tc1 = {5, 7, 11, 2, 1};
    int upper1 = 20;
    int lower1 = 16;
    int k1 = 3;

    cout << "tc1 pts = " << dietPerformance(tc1, k1, upper1, lower1) << endl;

    return 0;
}