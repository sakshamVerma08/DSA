#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{

    if (n == 1)
        return "1";

    string prev = countAndSay(n - 1);

    int count = 1, i = 1;
    string res = "";

    for (i; i < prev.size(); i++)
    {

        if (prev[i - 1] == prev[i])
            count++;

        else
        {

            res += '0' + count;
            res += prev[i - 1];
            count = 1;
        }
    }

    res += '0' + count;
    res += prev[i - 1];

    return res;
}
int main()
{

    int n1 = 4, n2 = 5;
    cout << "ans 1 = " << countAndSay(n1) << endl;
    cout << "ans2 = " << countAndSay(n2) << endl;

    return 0;
}