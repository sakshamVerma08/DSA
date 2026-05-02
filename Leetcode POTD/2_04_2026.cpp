#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    unordered_set<int> invalidDigits = {3, 4, 7};
    unordered_map<int, int> changingDigits;
    int ans = 0;

    bool checkValid(int num)
    {
        bool flag = false;

        while (num)
        {
            int digit = num % 10;

            if (invalidDigits.count(digit))
                return false;

            if (changingDigits.find(digit) != changingDigits.end())
                flag = true;

            num /= 10;
        }

        return flag;
    }

public:
    Solution()
    {
    }

    int rotatedDigits(int n)
    {

        this->changingDigits = {
            {6, 9},
            {9, 6},
            {2, 5},
            {5, 2}};

        for (int i = 1; i <= n; i++)
        {
            // looping from [1 to n].

            if (checkValid(i))
                ans++;
        }
        return ans;
    }
};

int main()
{

    int n;
    cin >> n;
    cin.ignore();
    Solution *s = new Solution();
    cout << s->rotatedDigits(n) << endl;

    return 0;
}