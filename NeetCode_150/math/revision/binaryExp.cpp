#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll tmp = power(a, b / 2);
    tmp *= tmp;

    if (b % 2 == 0)
        return tmp;
    else
        return tmp * a;
}

int main()
{

    ll a = 16;
    ll b = 9371;
    // find 16^9371

    cout << "a^b = " << power(a, b) << endl;
}