#include <iostream>
using namespace std;

int fact(int n)
{

    if (n == 1)
        return 1;

    int smallAns = fact(n - 1);

    return n * smallAns;
}

int main()
{

    int n1 = 5;
    int n2 = 4;

    cout << "ans1 = " << fact(n1) << endl;
    cout << "ans2 = " << fact(n2) << endl;

    return 0;
}