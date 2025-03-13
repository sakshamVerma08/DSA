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

// This is the Optimal Approach using Two Pointers
// Time complexity: O(n1 + n2)
// Space complexity : O(n1 + n2)
vector<int> unionArrays2(vector<int> a, vector<int> b)
{

    vector<int> unionArr;
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();

    while (i < n1 && j < n2)
    {

        if (a[i] <= b[j])
        {

            if (unionArr.size() == 0 || unionArr.back() != a[i])
                unionArr.push_back(a[i]);

            i++;
        }

        else
        {

            if (unionArr.size() == 0 || unionArr.back() != b[j])
                unionArr.push_back(b[j]);

            j++;
        }
    }

    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
            unionArr.push_back(a[i]);

        i++;
    }

    while (j < n2)
    {

        if (unionArr.size() == 0 || unionArr.back() != b[j])
            unionArr.push_back(b[j]);

        j++;
    }

    return unionArr;
}

void printVector(vector<int> &v)
{

    for (auto &elem : v)
    {
        cout << elem << " ";
    }

    cout << endl;
}
int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {2, 3, 4, 4, 5, 11, 12};

    vector<int> ans = unionArrays2(a, b);
    printVector(ans);

    return 0;
}