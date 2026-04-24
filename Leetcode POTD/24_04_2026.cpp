#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution()
    {
    }
    int furthestDistanceFromOrigin(string moves)
    {
        unordered_map<char, int> mpp;
        for (const char &ch : moves)
        {
            if (ch != '_')
                mpp[ch]++;
        }

        char greaterFreq;
        if (mpp['L'] >= mpp['R'])
            greaterFreq = 'L';

        else
            greaterFreq = 'R';

        int ans = 0;
        bool addInAns = true;
        if (greaterFreq == 'L')
            addInAns = false;

        for (int i = 0; i < moves.size(); i++)
        {
            // looping from 0 to n-1 (inclusive).
            if (moves[i] == greaterFreq || moves[i] == '_')
            {
                if (addInAns)
                {
                    ans++;
                    continue;
                }
                ans--;
            }
            else
            {
                if (addInAns)
                {
                    // R
                    ans--;
                    continue;
                }
                ans++;
            }
        }
        return abs(ans);
    }
};
int main()
{
    string inputStr;
    cout << "Enter the input string:" << endl;
    cin >> inputStr;

    Solution *s = new Solution();

    int ans = s->furthestDistanceFromOrigin(inputStr);

    cout
        << "ans = " << ans << endl;
    return 0;
}