#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Uses Brute Force approach (hashing)
// Time complexity = O(n1 + n2logn1)
// Space complexity = O(n1 + n2)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    map<int, int> m;
    vector<int> unionArr;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (m.find(nums1[i]) == m.end())
        {
            m[nums1[i]] = 1;
        }
    }

    for (int i = 0; i < nums2.size(); i++)
    {

        if (m.find(nums2[i]) != m.end())
        {
            if (m[nums2[i]] > 1)
                continue;

            unionArr.push_back(nums2[i]);
            m[nums2[i]]++;
        }
    }
    return unionArr;
}

// Read the Leetcode Editorial for this problem in the 'solutions'
// time complexity: O(n1logn + n2log m) 'n' and 'm' being the size of arr1 and arr2
// space complexity: O(1)
vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{

    int i = 0, j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ans;
    int last = -1;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (i < n1 && j < n2)
    {

        if (nums1[i] == nums2[j] && nums1[i] != last)
        {
            ans.push_back(nums1[i]);
            last = nums1[i];
            i++;
            j++;
        }

        else if (nums1[i] < nums2[j])
            i++;

        else
            j++;
    }

    return ans;
}

// This algorithm also uses a map data structure, but it is better than the one I used before
// go to leetcode editorial of this problem to see this algorithm.
// time complexity: O(n1 log n1) + O(n2 log n1)
// space complexity: O(n1)
vector<int> intersection3(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> seen;
    vector<int> ans;

    for (auto &elem : nums1)
    {
        seen[elem] = 1;
    }

    for (auto &elem : nums2)
    {
        if (seen[elem] == 1)
        {
            ans.push_back(elem);
            seen[elem] = 0;
        }
    }

    return ans;
}
void printVector(vector<int> &v)
{
    for (auto &elem : v)
    {
        cout << elem << " ";
    }

    cout << endl;
}
int main()
{

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {1, 2};

    vector<int> ans = intersection2(nums1, nums2);

    printVector(ans);

    return 0;
}