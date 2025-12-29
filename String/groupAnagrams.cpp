#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Algorithm:
/*
1. Define a map that can uniquely identify each anagram group.
2. Loop in the input array, for each given string in the array, store the original string in a copy variable, and sort the original string.
3. We will use this sorted string to generate the key of our map.



*/
vector<vector<string>> groupAnagrams(vector<string> arr)
{

    unordered_map<string, vector<string>> m;

    for (auto &s : arr)
    {

        string originalString = s;
        sort(s.begin(), s.end());

        m[s].push_back(originalString);
        // cout << "key:" << s << endl
        //      << "val: " << originalString << endl;
    }

    vector<vector<string>> ans;

    for (auto &pair : m)
    {
        ans.push_back(pair.second);
    }

    return ans;
}

void printAns(vector<vector<string>> ans)
{

    for (const auto &arr : ans)
    {

        for (auto &elem : arr)
        {

            cout << elem << " ";
        }

        cout << endl;
    }
}

int main()
{

    vector<string> arr1 = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = groupAnagrams(arr1);
    printAns(res);

    return 0;
}
