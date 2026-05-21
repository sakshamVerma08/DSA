#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{

private:
    int ans = 0;
    unordered_set<int> spp;

    void findAllPrefixes(int n)
    {

        string s = to_string(n);
        for (int i = 0; i < s.size(); i++)
        {

            string pref = "";

            for (int j = 0; j <= i; j++)
            {

                pref.push_back(s[j]);
            }

            spp.insert(stoi(pref));
        }
    }

    void checkPrefix(int n)
    {

        string s = to_string(n);
        for (int i = 0; i < s.size(); i++)
        {

            string pref = "";

            for (int j = 0; j <= i; j++)
            {

                pref.push_back(s[j]);
            }
            if (spp.count(stoi(pref)))
            {
                if (ans < pref.size())
                    ans = pref.size();

                continue;
            }
        }
    }

public:
    Solution()
    {
    }
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();

        for (int i = 0; i < n1; i++)
        {
            // looping from 0 to n1 -1 [0, n1-1].

            findAllPrefixes(arr1[i]);
        }

        for (int i = 0; i < n2; i++)
        {
            // looping from 0 to n2 -1 [0, n2-1]..

            checkPrefix(arr2[i]);
        }

        return ans;
    }
};

int main()
{
    vector<int> arr1, arr2;
    int length1, length2;
    cin >> length1 >> length2;
    cin.ignore();

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    stringstream ss1(s1), ss2(s2);

    int num1, num2;
    while (ss1 >> num1)
    {
        arr1.push_back(num1);
    }

    while (ss2 >> num2)
    {
        arr2.push_back(num2);
    }

    Solution *s = new Solution();

    cout << "Ans = " << s->longestCommonPrefix(arr1, arr2) << endl;

    return 0;
}