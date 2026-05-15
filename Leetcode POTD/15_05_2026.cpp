#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int ans = INT_MAX;

public:
    Solution()
    {
    }
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int st = 0, end = n - 1;

        int tmp = n / 2;

        while (st < end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] > arr[end])
                st = mid + 1;

            else
            {
                end = mid;
            }
        }

        return arr[st];
    }
};

int main()
{
    vector<int> arr;
    int length;
    cin >> length;
    cin.ignore();
    string elem;
    getline(cin, elem);
    stringstream ss(elem);
    int num;

    while (ss >> num)
    {
        arr.push_back(num);
    }

    Solution *s = new Solution();

    cout << " Ans = " << s->findMin(arr) << endl;

    return 0;
}