#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        // handling any edge cases which do not require to be processed or are already sorted.
        if (arr.size() == 1 || arr.size() == 0)
            return;

        // i represents the index pointing in the sorted array.
        // j represents the index pointing to the current element in the unsorted array.
        int i;
        for (int j = 1; j < arr.size(); j++)
        {

            int key = arr[j];
            i = j - 1;

            /* loop condition is as follows:
               i is greater than 0 and until the current element is greater than the element in the sorted array
               */
            while (i >= 0 && arr[i] > key)
            {
                // we move the 'i' element to the next index position.
                arr[i + 1] = arr[i];
                // Then we decrement i to compare the current element to the next element in sorted array.
                i -= 1;
            }

            // after the loop ends, we place the 'key' or current element to i + 1 index position.
            arr[i + 1] = key;
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
    sol.insertionSort(v1);
    sol.printVector(v1);
    return 0;
}