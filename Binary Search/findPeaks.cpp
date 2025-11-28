#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &vec)
{

    for (auto it = vec.begin(); it != vec.end(); it++)
    {

        cout << *it << " ";
    }

    cout << "\n";
}

vector<int> findPeaks(vector<int> &mountain)
{

    int n = mountain.size();
    vector<int> ans;

    for (int i = 1; i <= n - 2; i++)
    {

        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
            ans.emplace_back(i);
    }

    return ans;
}

vector<int> findPeaks2(vector<int> &mountain)
{

    int n = mountain.size();

    vector<int> ans;

    int low = 1, high = n - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        // If the mid element is the peak itself, then we compare it with the previous and next element, to
        // confirm whether it's peak or not, then we push it in the 'ans' array.
        if (mountain[mid] > mountain[mid - 1] && mountain[mid] > mountain[mid + 1])
            ans.push_back(mid);

        else if (mountain[mid] > mountain[mid - 1])
        {
            // If mid element is greater than the previous element, this means that we are standing
            // on a linearly increasing slope, so the peak must be in the right half. So we eliminate the left half.

            low = mid + 1;
        }

        // If the mid element is smaller than the previous element, this means that we are standing on a linearly
        // decreasing slope since the previous element (mid-1) is greater than the 'mid' element.
        // So we can safely assume that the peak lies to the left side, and hence we eliminate the right half.
        else
            high = mid - 1;
    }

    return ans;
}


int main()
{

    vector<int> arr = {1, 4, 3, 8, 5};

    vector<int> ans = findPeaks2(arr);

    printVector(ans);

    return 0;
}