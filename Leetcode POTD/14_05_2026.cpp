#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    Solution()
    {
    }

    bool isGood(vector<int> &arr)
    {
        int n = arr.size();
        auto max_it = std::max_element(arr.begin(), arr.end());
        int mx = *max_it;

        vector<int> base(mx + 1);
        int len = base.size();

        base[len - 1] = mx;
        base[len - 2] = mx;

        for (int i = 0; i < len - 2; i++)
        {
            // looping from [0 , len -3].

            base[i] = i + 1;
        }

        if (base.size() != arr.size())
            return false;

        unordered_map<int, int> mpp;
        for (const int &n : arr)
        {
            mpp[n]++;
        }

        for (int &n : base)
        {
            if (mpp.find(n) == mpp.end())
                return false;

            mpp[n]--;
        }

        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};

int main()
{

    vector<int> arr;
    Solution *s = new Solution();
    string line;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, line);
    stringstream ss(line);
    int tmp;

    while (ss >> tmp)
    {
        arr.emplace_back(tmp);
    }

    if (s->isGood(arr))
    {
        cout << "Ans = True" << endl;
    }
    else
    {
        cout << "Ans = False" << endl;
    }

    return 0;
}