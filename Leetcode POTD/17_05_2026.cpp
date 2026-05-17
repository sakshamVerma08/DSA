#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_set<int> vis;

    bool backtrack(vector<int> &arr, int n, int idx)
    {
        if (idx >= n || idx < 0 || vis.count(idx))
            return false;

        vis.insert(idx);
        if (arr[idx] == 0)
            return true;

        bool left = backtrack(arr, n, idx + arr[idx]);

        if (left)
            return true;

        bool right = backtrack(arr, n, idx - arr[idx]);
        if (right)
            return true;

        return false;
    }

public:
    Solution()
    {
    }
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        return backtrack(arr, n, start);
    }
};

int main()
{
    vector<int> arr;
    int length;
    cin >> length;
    cin.ignore();
    string elem;
    getline(cin, elem);
    stringstream ss(elem);
    int num;

    while (ss >> num)
    {
        arr.emplace_back(num);
    }

    cout << "Enter start:" << endl;
    int start;
    cin >> start;

    Solution *s = new Solution();

    bool ans = s->canReach(arr, start);
    if (ans)
        cout << "True" << endl;

    else
        cout << "False" << endl;

    return 0;
}