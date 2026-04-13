#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    int getMinDistance(vector<int> &arr, int target, int start)
    {
        // unordered_map<int,vector<int>> mpp;
        vector<int> v;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1 (inclusive).
            if (arr[i] == target)
                v.emplace_back(i);
        }

        int ans = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            // looping from 0 to v-1 (inclusive).
            ans = min(ans, abs(v[i] - start));
        }
        return ans;
    }
};

int main()
{

    Solution *s = new Solution();
    vector<int> arr = {1, 2, 3, 2, 4, 3, 5};
    int start = 3, target = 3;
    cout << "ans1 = " << s->getMinDistance(arr, target, start) << endl;
    return 0;
}