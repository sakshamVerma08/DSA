#include <iostream>
using namespace std;

// Recursive Implementation of Binary Search.

// time complexity: O()
// space complexity: O()
int binarySearch(int arr[], int n, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    else if (target > arr[mid])
        return binarySearch(arr, n, mid + 1, high, target);

    else
        return binarySearch(arr, n, low, mid - 1, target);
}

int main()
{
    int arr1[] = {3, 4, 6, 7, 9, 12, 16, 17};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "test case 1 = " << binarySearch(arr1, n1, 0, n1 - 1, 16) << endl;
    cout << "test case 2 = " << binarySearch(arr2, n2, 0, n2 - 1, 1) << endl;

    return 0;
}