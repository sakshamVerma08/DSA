#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> c(n, 0);

        int common = 0;

        for (int i = 0; i < n; i++)
        {
            freq[A[i]]++;

            if (freq[A[i]] == 2)
                common++;

            freq[B[i]]++;

            if (freq[B[i]] == 2)
                common++;

            c[i] = common;
        }

        return c;
    }
};

int main()
{

    vector<int> A;
    vector<int> B;
    int length;
    cin >> length;
    cin.ignore();

    string a_elem, b_elem;
    getline(cin, a_elem);
    getline(cin, b_elem);
    stringstream ss1(a_elem);
    stringstream ss2(b_elem);

    int num1, num2;

    while (ss1 >> num1)
    {
        A.push_back(num1);
    }

    while (ss2 >> num2)
    {
        B.push_back(num2);
    }

    Solution *s = new Solution();

    auto ans = s->findThePrefixCommonArray(A, B);

    for (const int &n : ans)
    {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}