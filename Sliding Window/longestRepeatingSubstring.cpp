#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N)
// space complexity: O(N)
int lengthOfLongestSubstring(string s)
{
    int l = 0;
    int longest = 0;
    unordered_set<int> st;

    for (int r = 0; r < s.size(); r++)
    {

        while (st.find(s[r]) != st.end())
        {
            st.erase(s[l]);
            l++;
        }

        longest = max(longest, r - l + 1);
        st.insert(s[r]);
    }

    return longest;
}
int main()
{

    return 0;
}