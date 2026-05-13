#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }
    int minMoves(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++)
        {
            int min = nums[i];
            int max = nums[n - 1 - i];
            if (min > max)
                swap(min, max);

            delta[2] += 2;
            delta[min + 1]--;
            delta[min + max]--;
            delta[min + max + 1]++;
            delta[max + limit + 1]++;
        }

        int res = n, moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++)
        {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;

    while (ss >> num)
    {
        arr.push_back(num);
    }

    int limit;
    cout << "\n"
         << "Enter limit: ";
    cin >> limit;
    Solution *s = new Solution();
    cout << "Ans = " << s->minMoves(arr, limit) << endl;

    return 0;
}