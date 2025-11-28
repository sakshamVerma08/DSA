#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string num)
{
    bool flag = false;
    string ans = "";

    int n = num.size();
    int temp;

    for (int i = n - 1; i >= 0; i--)
    {

        if (num.back() % 2 == 1)
            return num;

        else
        {

            // 'temp' stores the ASCII value of the current character that we're scanning.
            temp = num[i];

            if (temp % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
    }

    return ans;
}
int main()
{

    string tc1 = "5029";
    string tc2 = "1234";

    cout << "ans1 = " << largestOddNumber(tc1) << endl;
    cout << "ans2 = " << largestOddNumber(tc2) << endl;

    return 0;
}