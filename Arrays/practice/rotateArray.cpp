#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotateByOne(vector<int> &arr)
{
    int tmp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = tmp;
}

void rotateByD(vector<int> &arr, int d)
{
    vector<int> tmp;
    int n = arr.size();
    for (int i = 0; i < d; i++)
    {
        tmp.emplace_back(arr[i]);
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i < arr.size(); i++)
    {
        arr[i] = tmp[i - (n - d)];
    }
}

void rotateByD2(vector<int> &arr, int d)
{
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

void printVec(vector<int> &arr)
{
    for (const int &n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 5, -9, 22, 87, 35, 42};
    cout << "Test Case 2:" << endl;
    rotateByD2(arr, 3);
    printVec(arr);

    return 0;
}