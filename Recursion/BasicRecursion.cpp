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
};

int main()
{

    int num = 5;
    Solution sol;
    sol.printReversebyBacktracking(1, 5);

    return 0;
}