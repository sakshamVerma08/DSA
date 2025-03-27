#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int practiceDynamicWindow(vector<int> nums, int k)
{

    int start = 0, end = 0;

    while (end < nums.size())
    {

        if (end - start + 1 < k) // If the window is lesser than the required(k) value
            end++;

        else if (end - start + 1 == k)
        { // If window is equal to the required k value
            // Perform the required operations

            end++;
        }

        else if (end - start + 1 > k)
        { // If window size is greater than the required k value, then shrink the window, until it meets the criteria again

            while (end - start + 1 > k)
            {
                start++;
            }

            if (end - start + 1 == k)
            {
                // Perform the required operations
            }

            end++;
        }
    }
}

int main()
{

    return 0;
}