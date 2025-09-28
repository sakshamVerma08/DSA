#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        }

        else if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return ans;
}

int findLast(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }

        else if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return ans;
}

int count(vector<int> &arr, int n, int x)
{
    if (n == 0)
        return 0;
    int first = findFirst(arr, x);
    if (first == -1)
        return 0;

    int last = findLast(arr, x);

    return last - first + 1;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 3, 3, 5, 6};
    int x = 3;

    cout << "Frequency of 3 = " << count(arr, arr.size(), x);
}