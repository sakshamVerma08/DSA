#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int ans = 0;

public:
    Solution()
    {
    }

    int maxDistance(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != arr[i])
                    ans = max(ans, abs(i - j));
            }
        }
        return ans;
    }

    
};
int main()
{
    vector<int> arr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;

    while (ss >> num)
    {
        arr.push_back(num);
    }

    Solution *s = new Solution();
    cout << "ans = " << s->maxDistance(arr) << endl;

    return 0;
}