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

    void printKSubsequences(int arr[], vector<int> &ans, int n, int index, int sum, int s)
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
        printKSubsequences(arr, ans, n, index + 1, sum, s);
        ans.pop_back();
        s -= arr[index];
        // Don't pick the current element in the subsequence.
        printKSubsequences(arr, ans, n, index + 1, sum, s);
    }

    bool printOneSubsequence(int arr[], vector<int> &ans, int n, int index, int sum, int s)
    {
        // Prints only one random subsequence whose sum is equal to k

        if (index == n)
        {

            if (s == sum)
            {
                printVector(ans);
                return 1;
            }

            return 0;
        }

        s += arr[index];
        ans.push_back(arr[index]);
        // Pick the element at current index. We have to check whether after picking this element, have we got our "one subsequence" or not. If yes, then no need to run the recursion for "Not picking the current element".
        if (printOneSubsequence(arr, ans, n, index + 1, sum, s) == 1)
        {
            return 1;
        }

        ans.pop_back();
        s -= arr[index];

        if (printOneSubsequence(arr, ans, n, index + 1, sum, s) == 1)
            return 1;

        else
            return 0;
    }

    int CountSubsequences(int arr[], int n, int index, int sum, int s)
    {
        // This functions gives the number of subsequences whose sum is equal to k.
        // Time complexity of the function is O(2^n) because we have n elements, and for each element,
        // we are choosing two options.

        if (index == n)
        {
            if (s == sum)
                return 1;

            return 0;
        }

        s += arr[index];
        int left = CountSubsequences(arr, n, index + 1, sum, s);

        s -= arr[index];
        int right = CountSubsequences(arr, n, index + 1, sum, s);

        return left + right;
    }
};

int main()
{
    Solution sol;
    int arr[] = {1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    int sum = 3;
    cout << "Count = " << sol.CountSubsequences(arr, N, 0, sum, 0) << endl;
    sol.printKSubsequences(arr, ans, N, 0, sum, 0);
    return 0;
}