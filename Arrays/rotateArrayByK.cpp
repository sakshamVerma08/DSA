#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This approach is the brute force approach
// Time complexity: O(n)
// Space complexity: O(n)
vector<int> rotateArray(vector<int> arr, int k)
{

    int n = arr.size();
    vector<int> ans(n);

    if (n == 1)
        return arr;

    int fixedVal = n - k;

    for (int i = 0; i < n; i++)
    {

        if (fixedVal + i >= n)
        {

            ans[(fixedVal + i) - n] = arr[i];
            continue;
        }

        ans[fixedVal + i] = arr[i];
    }

    return ans;
}

vector<int> rotateArray2(vector<int> &arr, int k)
{
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

    vector<int> tc1 = {1, 2, 3, 4, 5};
    vector<int> tc2 = {9, 8, 7, 6, 5};

    return 0;
}
