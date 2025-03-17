#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n)
// space complexity: O(n) (hash Array)
vector<int> frequencyCount(vector<int> &arr)
{
    int N = arr.size();
    vector<int> hashArr(N, 0);

    for (auto &elem : arr)
    {

        hashArr[elem - 1] += 1;
    }

    return hashArr;
}

void printVector(vector<int> &v)
{

    for (auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> tc1 = {2, 3, 2, 3, 5};
    vector<int> tc2 = {3, 3, 3, 3};

    vector<int> ans1, ans2;

    ans1 = frequencyCount(tc1);
    ans2 = frequencyCount(tc2);

    printVector(ans1);
    printVector(ans2);

    return 0;
}
