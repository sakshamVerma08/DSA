#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void selectionSort(vector<int> &arr)
    {
        if (arr.size() == 0 || arr.size() == 1)
            return;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    void printVector(vector<int> &arr)
    {

        for (int elem : arr)
        {
            cout << elem << " ";
        }

        cout << endl;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {40, 20, 60, 50, 10};
    sol.selectionSort(v1);
    sol.printVector(v1);

    return 0;
}