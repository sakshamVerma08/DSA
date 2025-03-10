#include <iostream>
#include <vector>
using namespace std;

// Check if the given array is sorted in ascending order or not. If it is sorted, return 1, else return 0.
int isSorted(int n, vector<int> a)
{

    if (n == 1)
        return 1;

    int prev = -1;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {

        curr = a[i];

        if (curr < prev)
            return 0;

        prev = curr;
    }

    return 1;
}

int main()
{

    vector<int> tc1 = {1,2,3,4,5};
    vector<int> tc2 = {1,2,3,4,5,0};

    cout<< isSorted(tc1.size(),tc1)<<endl;
    cout<< isSorted(tc2.size(),tc2)<<endl;

    return 0;
}