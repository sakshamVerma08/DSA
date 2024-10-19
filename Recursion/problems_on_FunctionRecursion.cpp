#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArray(int arr[], int N)
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverseArray1(int nums[], int N)
    {
        if (N == 0)
            return;

        int start = 0, end = N - 1;

        while (start <= end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void reverseArray2(int nums[], int left, int right)
    { // This function uses two pointers, left and right, two reverse the array using recursion.

        if (right <= left)
            return;

        swap(nums[left], nums[right]);
        reverseArray2(nums, left + 1, right - 1);
    }

    void reverseArray3(int nums[], int n, int i)
    {
        // This function uses a single pointer to reverse the array using Recursion.

        if (i >= n / 2)
            return;

        swap(nums[i], nums[n - i - 1]);
        reverseArray3(nums, n, i + 1);
    }

    bool isPallindrome(string str, int left, int right)
    {
        int ans = 1;
        if (str.length() == 0)
            return ans;

        if (str[left] != str[right])
            return 0;

        if (right <= left)
            return 1;

        isPallindrome(str, left + 1, right - 1);
        return ans;
    }

    bool isPallindrome2(string str, int left)
    {
        if (str.length() == 0)
            return 1;

        if (left >= str.length() / 2)
            return 1;

        if (str[left] != str[str.length() - left - 1])
            return 0;

        return isPallindrome2(str, left + 1);
    }

    int fib(int n)
    { // This function finds the nth fibonacci number from the fibonacci series
        // Fib Series: 0 1 1 2 3 5 8 13 21 34 55 .....

        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }

    // The time complexity of the above function will be roughly
    // equal to 2^n.
};

int main()
{
    Solution sol;
    
    return 0;
}