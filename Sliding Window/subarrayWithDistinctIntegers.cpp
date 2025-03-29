#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int helper(vector<int> &arr, int b)
{
    unordered_map<int, int> freq;
    int left = 0, count = 0;

    for (int right = 0; right < arr.size(); right++)
    {

        freq[arr[right]]++;

        while (freq.size() > b)
        {
            // shrink the window now

            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                freq.erase(arr[left]);

            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

int goodSubarrays(vector<int> &arr, int n, int b)
{
    return helper(arr, b) - helper(arr, b - 1);
}
int main()
{

    vector<int> tc1 = {1, 2, 1, 2, 3};

    cout << "tc1 = " << goodSubarrays(tc1, tc1.size(), 3) << endl;

    return 0;
}