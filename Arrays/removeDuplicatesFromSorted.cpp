#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This is brute force approach, that uses a Set data structure.
int removeDuplicates(vector<int> &arr, int n)
{
    if (n == 1)
        return n;

    set<int> s;

    for (auto elem : arr)
    {
        s.insert(elem);
    }

    int index = 0;
    for (auto elem : s)
    {
        arr[index] = elem;
        index++;
    }

    return s.size();
}

int removeDuplicates2(vector<int> &arr, int n)
{

    if (n == 1)
        return n;

    int i = 0;

    for (int j = i + 1; j < n; j++)
    {

        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}
int main()
{

    vector<int> tc1 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int n1 = tc1.size();

    cout << "test case 1 : " << removeDuplicates2(tc1, n1) << endl;

    vector<int> tc2 = {1, 2, 2, 3};
    int n2 = tc2.size();

    cout << "test case 2 : " << removeDuplicates2(tc2, n2) << endl;
    return 0;
}