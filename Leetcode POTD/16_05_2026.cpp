#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int st = 0, end = n - 1;

        while (st < end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] > arr[end])
            {
                st = mid + 1;
            }
            else if (arr[mid] < arr[end])
                end = mid;

            else
                end--;
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
        arr.emplace_back(num);
    }

    Solution *s = new Solution();

    cout << "Ans = " << s->findMin(arr) << endl;

    return 0;
}