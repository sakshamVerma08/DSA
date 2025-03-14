#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// uses mapping approach
// time complexity : O(N) + O(N log N)
// space complexity: O(N)
int getSingleElement(vector<int> &arr)
{

    map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {

        if (m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;
            continue;
        }

        m[arr[i]] = 1;
    }

    map<int, int>::iterator iter = m.begin();

    while (iter != m.end())
    {
        if (iter->second == 1)
            return iter->first;

        iter++;
    }
}

// Uses the Bitwise Operator
// Time complexity: O(N)
// space complexity: O(1)
int getSingleElement2(vector<int> &arr){

    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }

    return ans;
}



int main()
{

    vector<int> tc1 = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    vector<int> tc2 = {0, 0, 1, 2, 2};

    cout << "tc1 : " << getSingleElement2(tc1) << endl;
    cout << "tc2 : " << getSingleElement2(tc2) << endl;
    return 0;
}