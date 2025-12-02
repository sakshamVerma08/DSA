#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    auto cmp = [](pair<char, int> p1, pair<char, int> p2)
    {
        return p1.second < p2.second;
    };

    unordered_map<char, int> mp;

    for (auto &ch : s)
    {
        mp[ch]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

    for (auto &pair : mp)
    {

        pq.push(pair);
    }

    string result = "";

    while (!pq.empty())
    {

        pair<char, int> p = pq.top();
        pq.pop();
        result.append(p.second, p.first);
    }

    return result;
}
int main()
{

    string s = "xyzzz";

    cout << "ans = " << frequencySort(s) << endl;

    return 0;
}