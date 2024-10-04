#include <iostream>
using namespace std;

void mergeSortedArray(int arr[], int left, int mid, int right)
{

    int n1 = mid - left + 1, n2 = right - mid;
    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[i + left];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {

        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }

        else
        {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{

    int left = l;
    int right = r;
    int mid = (left + right) / 2;
    if (left >= right)
        return;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    mergeSortedArray(arr, left, mid, right);
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
