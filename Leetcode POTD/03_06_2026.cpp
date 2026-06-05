
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> lst, wst, ld, wd;
    int n, m;
    cin >> n >> m;
    cin.ignore();

    string water, land, land_duration, water_duration;

    getline(cin, land);
    getline(cin, land_duration);

    getline(cin, water);
    getline(cin, water_duration);

    stringstream ss1(land), ss2(water);
    stringstream d1(land_duration), d2(water_duration);

    int x1, x2;

    while (d1 >> x1)
    {
        ld.push_back(x1);
    }
    while (d2 >> x2)
    {
        wd.push_back(x2);
    }

    while (ss1 >> n)
    {
        lst.push_back(n);
    }
    while (ss2 >> m)
    {
        wst.push_back(m);
    }

    Solution *s = new Solution();
    cout << "Ans = " << s->earliestFinishTime(lst, ld, wst, wd) << endl;
    return 0;
}
