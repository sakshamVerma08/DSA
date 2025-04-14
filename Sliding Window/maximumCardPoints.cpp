#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// YOU HAVE TO SEARCH FOR ALL POSSIBILITIES FOR K ELEMENTS FROM THE FRONT AS WELL AS FROM THE BACK
// time complexity: O(2k)
// space complexity: O(1)
int maxScore(vector<int> &cardPoints, int k)
{
    int res = 0;
    int n = cardPoints.size();

    for (int i = 0; i < k; i++)
    {
        res += cardPoints[i];
    }

    int curr = res;
    int last = k - 1;

    while (last >= 0)
    {
        curr -= cardPoints[last];
        curr += cardPoints[n - k + last];
        last--;
        res = max(res, curr);
    }

    return res;
}
int main()
{
    return 0;
}