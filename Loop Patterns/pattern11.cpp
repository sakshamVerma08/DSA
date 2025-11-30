#include <iostream>
using namespace std;

void printPattern11(int n)
{

    bool bit = false;
    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 1)
            bit = false;

        else
            bit = true;

        for (int j = 0; j < i + 1; j++)
        {
            cout << bit;
            bit = !bit;
        }
        cout << endl;
    }
}

int main()
{

    printPattern11(5);
    return 0;
}