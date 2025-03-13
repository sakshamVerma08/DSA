#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Uses Nested Loop approach
// Time complexity: Hypothetically O(N^2)
// Space complexity: O(1)
int findMissing1(vector<int> &a, int N)
{
    int flag;

    for (int i = 1; i <= N; i++)
    {

        flag = 0;

        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            return i;
    }
}

// Uses a poniter and a single pass to solve the problem
// Time complexity: O(N + NlogN)
// space complexity: O(1)

// the only difference is that in this function, the job of the nested inner loop is done by the idx pointer, which is more efficient.
int findMissing2(vector<int> &a, int N)
{

    int idx = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < N; i++)
    {
        if (i != a[idx])
            return i;

        idx++;
    }

    return N;
}

// This approach uses hashing. Hashing is basically counting the frequency of each element.
// We use a hash array for this purpose.
// time complexity: O(2N)
// space complexity: O(N)
int findMissing3(vector<int> &a, int N)
{

    vector<int> hashArr(N, 0);

    int idx = 0;

    for (auto &elem : a)
    {
        idx = elem - 1;

        hashArr[idx] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (hashArr[i] == 0)
            return i + 1;
    }
}

int findMissing3(vector<int> &a, int N){


}


int main()
{

    vector<int> tc1 = {1, 2, 3, 5};
    int n1 = sizeof(tc1) / sizeof(tc1[0]) + 1;

    vector<int> tc2 = {2, 3, 5, 1};
    int n2 = sizeof(tc2) / sizeof(tc2[0]) + 1;

    vector<int> tc3 = {};
    int n3 = 1;

    cout << "TC1 : " << findMissing1(tc1, n1) << endl;
    cout << "TC2 : " << findMissing1(tc2, n2) << endl;
    cout << "TC3 : " << findMissing1(tc3, n3) << endl;

    return 0;
}