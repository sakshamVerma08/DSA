#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N)
// space complexity: O(1)
void sortColors(vector<int> &nums)
{
    int zeroes = 0, ones = 0, twos = 0;

    for (auto &elem : nums)
    {
        if (elem == 0)
            zeroes++;

        else if (elem == 1)
            ones++;

        else
            twos++;
    }

    for (int i = 0; i < nums.size(); i++)
    {

        if (zeroes != 0)
        {
            nums[i] = 0;
            zeroes--;
            continue;
        }

        if (ones != 0)
        {
            nums[i] = 1;
            ones--;
            continue;
        }

        if (twos != 0)
        {
            nums[i] = 2;
            twos--;
        }
    }
}

void sortColors2(vector<int> &nums)
{
    
}

void printVector(vector<int> &vec){
    for (auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> tc1 = {0, 2, 2, 1, 0, 1, 2};
    vector<int> tc2 = {0, 0, 2, 0, 1, 2, 1, 0};

    return 0;
}