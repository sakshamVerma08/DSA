#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }
    bool checkPrime(long long n)
    {
        int cnt = 0;
        for (int i = 1; i * i <= n; i++)
        {
            // looping from 1 to n.
            if (n % i == 0)
                cnt += 2; // I've added count by 2, because let's say for i = 3, I had an arbitrary x value which when I multiplied by 3, resulted in n, therefore 3 being a factor of 'n'. But this also means that i can count that arbitrary number x as well, instead of going till x in future, and then counting it.
                          // This is because in future, when i loop till x, x*3 will also result in 'n', so instead of looping till x, i will loop lesser
                          // This way i only need to loop till square root of n.
        }

        return cnt == 2;
    }
};
int main()
{
    long long n = 1e9 + 7;
    Solution *s = new Solution();

    if (s->checkPrime(n))
        cout << "n is prime" << endl;
    else
        cout << "n is not prime" << endl;

    return 0;
}