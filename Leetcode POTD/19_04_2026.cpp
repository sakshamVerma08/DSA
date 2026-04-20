#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int ans = 0;

    int binary_search(int st, int end, vector<int> &arr2, int target)
    {
        int idx = -1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (arr2[mid] >= target)
            {
                idx = mid;
                st = mid + 1;
            }
            else
            {
                // arr2[mid] < target.
                end = mid - 1;
            }
        }
        return idx;
    }

public:
    Solution()
    {
    }
    int maxDistance(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();

        for (int i = 0; i < n1; i++)
        {
            // looping from 0 to n1-1 in left to right direction.
            int j = binary_search(i, n2 - 1, arr2, arr1[i]);

            if (j == -1)
                continue;

            ans = max(ans, j - i);
        }

        return ans;
    }
};

int main()
{

    vector<int> arr1, arr2;
    int n1, n2;
    cin >> n1 >> n2;
    cin.ignore();

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    stringstream ss1(line1);
    stringstream ss2(line2);
    int num;
    while (ss1 >> num)
    {
        arr1.emplace_back(num);
    }
    while (ss2 >> num)
    {
        arr2.emplace_back(num);
    }

    Solution *s = new Solution();
    int ans = s->maxDistance(arr1, arr2);
    cout << "ans: " << ans << endl;
    return 0;
}