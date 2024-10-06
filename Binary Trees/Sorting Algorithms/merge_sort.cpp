#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArray(int arr[], int N)
    {

        for (int i = 0; i < N; i++)
        {

            cout << arr[i] << "  ";
        }
    }

    void mergeSortedArrays(int arr[], int start, int mid, int end)
    {

        int leftSize = mid - start + 1, rightSize = end - mid;
        int leftArr[leftSize], rightArr[rightSize];

        // Creating the left and right subarrays

        for (int i = 0; i < leftSize; i++)
        {
            leftArr[i] = arr[start + i];
        }

        for (int j = 0; j < rightSize; j++)
        {
            rightArr[j] = arr[mid + j + 1];
        }

        // We take 3 variables: i for leftSubArray , j for rightSubArray and k for the main array
        int i = 0, j = 0, k = start;

        // In while loop we make sure that both the pointers are within the array, if not, then we quit the loop.
        while (i < leftSize && j < rightSize)
        {

            // Inside the while loop we compare the elements of left and right Subarray and then push the smaller element in the main array

            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
                k++;
            }

            else
            {
                arr[k] = rightArr[j];
                j++;
                k++;
            }
        }

        if (i == leftSize)
        {
            // This means that the pointer in left Subarray has run out of bounds, but elements are left to be processed in the
            // right subarray , so we run a while loop and push all the elements of right subarray in the main array

            while (j < rightSize)
            {
                arr[k] = rightArr[j];
                j++;
                k++;
            }
        }

        else if (j == rightSize)
        {
            // This means the reverse of the above "if" statement. The right subarray pointer has run out of bounds
            while (i < leftSize)
            {
                arr[k] = leftArr[i];
                i++;
                k++;
            }
        }
    }

    void mergeSort(int arr[], int st, int end)
    {
        if (st >= end)
            return;

        //  Calculate the mid point from where the array is to be divided.
        int mid = (st + end) / 2;

        // Left Sub-array
        mergeSort(arr, st, mid);

        // Right Sub-array
        mergeSort(arr, mid + 1, end);

        // "Approach on how to think this step" : We merge the single element arrays, then it returns and continues the recursion.
        mergeSortedArrays(arr, st, mid, end);
    }
};

int main()
{

    int arr[] = {38, 27, 43, 10};
    int arr2[] = {40, 39, 38, 37, 36, 35};
    int arr3[] = {1, 5, 1, 3, 2, 10, 2, 4, 8, 7, 7};

    int N = sizeof(arr) / sizeof(arr[0]);
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int N3 = sizeof(arr3) / sizeof(arr3[0]);

    Solution s;
    int start = 0, end2 = N2 - 1;
    int end3 = N3 - 1;

    s.mergeSort(arr, start, end2);
    s.mergeSort(arr3, start, end3);

    s.printArray(arr2, N2);
    cout << endl
         << "Array 3" << endl;
    s.printArray(arr3, N3);
    return 0;
}