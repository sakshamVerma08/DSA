#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This Brute force approach uses Ordered Set
// Time Complexity: O(n1 log n  + n2 log n) + O(n1 + n2)
// Space Complexity: O(n1 + n2) + O(n1 + n2)
// the second O(n1 + n2) is just for returning the answer (ans) array.
vector<int> unionArrays(vector<int> &a, vector<int> &b)
{

    set<int> st;
    vector<int> ans;

    for (auto &elem : a)
    {
        st.insert(elem);
    }

    for (auto &elem : b)
    {
        st.insert(elem);
    }

    for (auto &elem : st)
    {
        ans.push_back(elem);
    }

    return ans;
}

vector<int> unionArrays2(vector<int> &a, vector<int> &b)
{
}
int main()
{

    return 0;
}