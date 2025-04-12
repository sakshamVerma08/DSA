#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestAlternatingSubarray(vector<int> &nums, int threshold)
{
    int ans = INT_MIN;
    int start = 0;
    int n = nums.size();
    int lastElem;
    for (int end = 0; end < n; end++)
    {

        if (nums[end] % 2 != 0 && nums[end] > threshold)
            end++;

        else
        {
            start = end;
            lastElem = nums[end];
            end++;

            while (end < n - 1)
            {
                if (lastElem % 2 != nums[end] % 2 && nums[end] <= threshold)
                {
                    lastElem = nums[end];
                    end++;
                }

                else
                {
                    start = end;
                    lastElem = nums[end];

                    if (nums[end] > threshold)
                    {
                        start++;
                        end++;
                    }

                    else
                        end++;
                }
            }

            ans = max(ans, end - start + 1);
        }
    }

    return ans - 1;
}
int main()
{

    return 0;
}