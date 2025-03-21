#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N^3)
// space complexity: O(N)
int totalNumbers(vector<int> &digits)
{
    unordered_set<int> st;
    int N = digits.size();

    for (int i = 0; i < N; i++)
    {

        if (digits[i] == 0)
            continue;

        for (int j = 0; j < N; j++)
        {

            if (j == i)
                continue;

            for (int k = 0; k < N; k++)
            {
                if (k == i || k == j)
                    continue;

                if (digits[k] % 2 == 0)
                {
                    st.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
    }

    return st.size();
}

int main()
{

    vector<int> tc1 = {1, 2, 3, 4};
    cout << "tc1 : " << totalNumbers(tc1) << endl;
    return 0;
}