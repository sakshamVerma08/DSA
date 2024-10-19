#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printVector(vector<int> &v)
    {
        if (v.size() == 0)
            cout << "[]";

        else
        {
            for (auto elem : v)
            {
                cout << elem << " ";
            }
            cout << "\n";
        }
    }
    void printArraySubsequences(int arr[], vector<int> &ans, int n, int index)
    {
        if (index >= n)
        {
            printVector(ans);
            return;
        }

        ans.push_back(arr[index]);

        // Take the current index element in your subsequence
        printArraySubsequences(arr, ans, n, index + 1);

        // Don't take the current index element in your subsequence
        ans.pop_back();
        printArraySubsequences(arr, ans, n, index + 1);
    }
    // Time complexity of above code = O(2^n) x n
    // Space complexity of above code = O(N)

    void kSumSubsequences(int arr[], vector<int> &ans, int n, int index, int sum, int s)
    { // Prints those subsequences only whose sum is equal to the given value for the sum.
        if (index == n)
        {
            if (s == sum)
                printVector(ans);

            return;
        }

        ans.push_back(arr[index]);
        s += arr[index];
        // Pick the current element in the subsequence.
        kSumSubsequences(arr, ans, n, index + 1, sum, s);
        ans.pop_back();
        s -= arr[index];
        // Don't pick the current element in the subsequence.
        kSumSubsequences(arr, ans, n, index + 1, sum, s);
    }
};

int main()
{
    Solution sol;
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 3;
    vector<int> ans;
    sol.kSumSubsequences(arr, ans, n, 0, sum, 0);
    return 0;
}