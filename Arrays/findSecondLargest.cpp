#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// You can do this problem by sorting the array as well as by other approaches.
int getSecondLargest(int n, vector<int> &arr)
{

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int &elem : arr)
    {
        if (elem > largest)
        {
            secondLargest = largest;
            largest = elem;
        }

        if (elem > secondLargest)
            secondLargest = elem;
    }
    cout << "second largest = " << secondLargest << endl;
    return secondLargest;
}

int getSecondSmallest(int n, vector<int> &arr)
{

    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int &elem : arr)
    {

        if (elem < smallest)
        {
            secondSmallest = smallest;
            smallest = elem;
        }

        if (elem < secondSmallest)
            secondSmallest = elem;
    }

    return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    vector<int> ans(2);

    int sL = getSecondLargest(n, a);
    int sS = getSecondSmallest(n, a);

    ans[0] = sL;
    ans[1] = sS;
    return ans;
}

int main()
{

    vector<int> tc1 = {3, 4, 5, 2};
    vector<int> tc2 = {2, 5};

    vector<int> a1 = getSecondOrderElements(tc1.size(), tc1);

    for (int &elem : a1)
    {
        cout << elem << " ";
    }

    return 0;
}