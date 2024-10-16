#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(const string &s)
    {
        const char *arr = s.c_str(); // Initialize pointer to the first character of the string
        while (*arr == ' ')
        { // Skip leading whitespace
            arr++;
        }

        int sign = 1;
        int ans = 0;

        if (*arr == '-')
        {
            sign = -1;
            arr++;
        }
        else if (*arr == '+')
        {
            arr++;
        }

        while (*arr && isdigit(*arr))
        { // Check if the current character is a digit
            int digit = *arr - '0';

            // Check for overflow and underflow
            if (sign == 1 && (ans > (INT_MAX - digit) / 10))
            {
                return INT_MAX;
            }
            if (sign == -1 && (ans > (INT_MAX - digit) / 10))
            {
                return INT_MIN;
            }

            ans = ans * 10 + digit;
            arr++;
        }

        return ans * sign;
    }
};

int main()
{
    Solution sol;
    string tc1 = "-42", tc2 = "   42", tc3 = "1234abcd", tc4 = "  -04 23", tc5 = "-91283472332";
    int ans1, ans2, ans3, ans4, ans5;

    cout << "ans2 = " << sol.myAtoi(tc2);
    return 0;
}