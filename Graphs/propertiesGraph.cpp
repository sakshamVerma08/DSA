#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int intersect(vector<int> a, vector<int> b)
    {

        vector<int> intersection;

        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));

        return intersection.size();
    }

    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        int ans = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < properties.size(); i++)
        {

            for (int j = 0; j < properties.size(); j++)
            {

                if (mpp[i] == j)
                    continue;

                if (i == j)
                    continue;

                else
                {
                    if (intersect(properties[i], properties[j]) >= k)
                    {
                        mpp[j] = i;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
// Test for this test case : properties = [ [1,1], [1,1]] and k = 2
int main()
{

    return 0;
}