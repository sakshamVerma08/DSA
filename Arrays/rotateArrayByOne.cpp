#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This uses the brute force way to rotate an array by one
// Time complexity: O(n)
// Space complexity : O(n)
vector<int> rotateArray(vector<int> &arr, int n)
{

    if (n == 1)
        return arr;

    vector<int> ans(n);

    int i = 0;

    for (int x = 1; x < n; x++)
    {
        ans[i] = arr[x];
        i++;
    }

    ans[i] = arr[0];
    return ans;
}

// The below function is the optimized way to rotate an array by one
// Time complexity: O(n)
// Space complexity: O(1)
vector<int> rotateArray2(vector<int> &arr, int n)
{

    if (n == 1)
        return arr;

    int temp = arr[0];
    int x = 0;

    for (int i = 1; i < n; i++)
    {

        arr[x] = arr[i];
        x++;
    }

    arr[x] = temp;
    return arr;
}

void printVector(vector<int> &arr)
{

    for (auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> tc1 = {1, 2, 3, 4, 5};
    vector<int> tc2 = {9, 8, 7, 6, 5};

    vector<int> ans1 = rotateArray(tc1, 5);
    vector<int> ans2 = rotateArray2(tc2, 5);

    printVector(ans1);
    printVector(ans2);

    return 0;
}