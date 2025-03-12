#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Uses Brute Force method
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> moveZeros(int n, vector<int> a)
{

    vector<int> ans(n);
    int cnt = 0;
    int x = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            cnt++;
            continue;
        }

        ans[x] = a[i];
        x++;
    }

    while (cnt != 0)
    {
        ans[x] = 0;
        x++;
        cnt--;
    }

    return ans;
}

vector<int> moveZeros2(int n, vector<int> a)
{
    int j = -1;

    for (int i = 0; i < n; i++)
    {

        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return a;

    for (int i = j + 1; i < n; i++)
    {

        if (a[i] != 0)
        {
            swap(a[j], a[i]);
            j++;
        }
    }

    return a;
}

void printVector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> tc1 = {0, 0, 0, 1};
    vector<int> tc2 = {1, 0, 5, 3, 0, 2, 0};

    vector<int> ans = moveZeros2(tc1.size(), tc1);
    printVector(ans);
    cout << "Test case 2: " << endl;
    vector<int> ans2 = moveZeros2(tc2.size(), tc2);
    printVector(ans2);

    return 0;
}