#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N)
// Space compleixty: O(N)
int maximum69Number(int num)
{
    string charArray = to_string(num);
    string str = "9";

    for (int i = 0; i < charArray.size(); i++)
    {

        if (charArray[i] == '6')
        {
            charArray.replace(i, 1, str);
            break;
        }
    }

    return stoi(charArray);
}
int main()
{

    return 0;
}