#include <iostream>

using namespace std;



void merge(int arr[], int begin, int mid, int end)
{

    // Create L ← A[begin..mid] and M ← A[mid+1..end]
    int const n1 = mid - begin + 1;
    int const n2 = end - mid;

    //int L[n1], M[n2];
    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[begin + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = begin;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[begin..end]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[begin..end]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        // mid is the point where the array is divided into two subarrays
        int mid = begin + (end - begin) / 2;

        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted subarrays
        merge(arr, begin, mid, end);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    int times;

    cin >> times;
    for (int t = 0; t < times; t++)
    {
        int length;
        cin >> length;
        int *list = new int[length];
        for (int i = 0; i < length; i++)
        {
            cin >> list[i];
        }
        mergeSort(list, 0, length - 1);
        printArray(list, length);
        delete[] list;
    }
}