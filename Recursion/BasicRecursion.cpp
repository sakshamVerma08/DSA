#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printName(string s, int N)
    {
        // Prints the name n times using Recursion.
        // Time Complexity = O(N), Space Complexity = O(N) (Internal memory uses Call Stack space).

        // Base Case
        if (N == 0)
            return;

        printName(s, N - 1);

        cout << s << "  ";
    }

    // print from 1 to N , in the same order, eg = 1,2,3,4 for N = 4.
    void printLinearly(int num, int i, int N)
    // Time complexity = O(N) and space complexity = O(N) (Internal call stack memory).
    {
        if (i > N)
            return;

        cout << num << "  ";
        printLinearly(num + 1, i + 1, N);
    }

    // Prints the numbers from N to 1. eg) N = 5, so output = 5,4,3,2,1.
    void printReverseOrder(int N)
    { // Time complexity = O(N) & Space Complexity = O(N) (Call stack internal space).
        if (N == 0)
            return;

        cout << N << "  ";
        printReverseOrder(N - 1);
    }

    // Prints the numbers from 1 -> N , but by the use of Backtracking.
    void printbyBacktracking(int N)
    { // Time complexity = O(N) and space complexity = O(N) using Call Stack.
        if (N == 0)
            return;

        printbyBacktracking(N - 1);
        cout << N << "  ";
    }

    // Prints the numbers from N -> 1 but by using Backtracking.
    void printReversebyBacktracking(int i, int N)
    { // Time complexity = O(N) and space complexity = O(N) using Internal memory (Call Stack).
        if (i > N)
            return;

        printReversebyBacktracking(i + 1, N);
        cout << i << "  ";
    }

    int sumofNaturalNumbers(int N, int ans)
    { // Prints the sum of first N natural numbers. This way , we do use Parameters in Recursion.
        if (N == 0)
            return 0;

        sumofNaturalNumbers(N - 1, ans);
        ans += N;

        return ans;
    }

    int sumofNaturalNum(int N)
    {
        if (N < 1)
            return 0;

        return (N + sumofNaturalNum(N - 1));

        // This does the same as above, but doesn't use any Parameters.
    }

    int productofN(int N){
        // Functionl recursion function that prints the product of first N numbers.

        if (N == 1)
        return 1;

        return N * productofN(N-1);
    }
};

int main()
{

    int num = 5;
    Solution sol;
    int ans = 0;
    cout << sol.productofN(5) << endl;

    return 0;
}