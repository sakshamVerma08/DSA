#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubarrays(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {

            for (int k = i; k < j; k++)
            {

                cout << nums[k] << " ";
            }
            cout << ",";
        }

        cout << endl;
    }
    cout << endl;
}
int main()
{

    vector<int> tc1 = {1, 2, 3, 4, 5};
    vector<int> tc2 = {-3, 1, 2, 4};

    printSubarrays(tc1);
    printSubarrays(tc2);

    return 0;
}