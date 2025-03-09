#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int n, vector<int> &arr)
{

    if (n == 1)
        return arr[0];

    sort(arr.begin(), arr.end());

    return arr[n - 1];
}

int findLargestElement2(int n, vector<int> &arr)
{

    if (n == 1)
        return arr[0];

    int ans = 0;

    for (int &elem : arr)
    {
        if (elem > ans)
            ans = elem;
    }
    return ans;
}

int main()
{

    vector<int> tc1 = {5, 3, 1, 100, 800, 500, 2};
    cout << findLargestElement(tc1.size(), tc1) << endl;
    cout << "largest elem2 = " << findLargestElement2(tc1.size(), tc1) << endl;
    return 0;
}