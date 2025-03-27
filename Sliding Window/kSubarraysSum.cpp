#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kSubarraySum(vector<int> &nums, int k)
{

    // Static size Sliding Window
    int i = 0;
    int j = k - 1;

    int sum = 0;
    while (j < nums.size())
    {

        if (j - i + 1 < k)
        {
            sum += nums[j];
            j++;
        }

        else
        {

            sum += nums[j];
            cout << sum << " ";

            sum -= nums[i];
            i++;
            j++;
        }
    }
}


int main()
{
    vector<int> tc1 = {3, -2, 5, 4, 10, 11};

    cout << "tc1 = " << kSubarraySum(tc1, 2) << endl;

    return 0;
}