#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findBeauty(vector<int> &freq)
{

    int maxVal = 0, minVal = INT_MAX, sum = 0;

    for (auto &f : freq)
    {

        if (f > 0)
        {

            maxVal = max(f, maxVal);
            minVal = min(f, minVal);
        }
    }

    sum = maxVal - minVal;

    return sum;
}

void setZero(vector<int> &freq)
{

    for (auto it = freq.begin(); it != freq.end(); it++)
    {

        *it = 0;
    }
}

int beautySum(string s)
{
    int ans = 0, n = s.size();
    vector<int> freq(26, 0); // Hash Table.

    for (int i = 0; i < n; i++)
    {

        setZero(freq);

        for (int j = i; j < n; j++)
        {

            freq[s[j] - 'a']++;
            ans += findBeauty(freq);
        }
    }

    return ans;
}

// ************************
// ************************

int main()
{

    string s1 = "fjnbqrzhwnkvvnlnoisixgkeujkcwtufnxpwumvokdkuwpzhzqwjtbnpjuxflgaccgkeryaapjokfpaygmdjbfuswtdzdpnnivvzrfurhjiajjsrgyhremlyptqejdyoiwhxjxmkeucllmazclxfpikywdphdjbhoogypiyidotlqdfwymmypektnsiidhwtfyuwvxtnuqvlwuoqxdsfbogoluuinlczwejngcedfxofwnenxshosyitsqxcafbpvvhwimwvuqddrdhepiiynrxhmzomlmmgsdjavsehdewtbwtnhlfprhnw";

    string s2 = "ascbsgkqhggtsgtnufuzmmtfcjjpchtzluwqkbxmntpkzxkodnenlxkavdzrgijduftnsphuiluswkfrpopooxyguwbfhrfhkadrzecxpcpvydfblfctmxuzbzksazfjoxdwhlwsnjgnonxwtpwbqpidncxnuerxbxprtznafgbwyfftrwwisileapvinzzsojvshoozkfkozqhsbsaopdplpvpwzjtvlzgtbzej";

    cout << "ans1 = " << beautySum(s1) << endl;
    cout << "ans2 = " << beautySum(s2) << endl;
    return 0;
}