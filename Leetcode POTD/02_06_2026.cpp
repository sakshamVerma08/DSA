#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int ans = INT_MAX;

public:
    Solution()
    {
    }
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Case A: Land -> Water
        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1

            int temp = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++)
            {
                // looping from 0 to m-1
                int waterSt = max(temp, waterStartTime[j]);
                int fin = waterSt + waterDuration[j];
                ans = min(fin, ans);
            }
        }

        // Case B: water -> land
        for (int i = 0; i < m; i++)
        {
            // looping from 0 to m-1

            int temp = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++)
            {
                // looping from 0 to n-1
                int waterSt = max(temp, landStartTime[j]);
                int fin = waterSt + landDuration[j];
                ans = min(fin, ans);
            }
        }

        return ans;
    }
};

int main()
{
}