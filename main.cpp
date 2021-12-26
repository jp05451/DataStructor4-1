#include <iostream>

using namespace std;

template <class C>
void merge(C arr[], int begin, int mid, int end)
{

    int const subArrayLeft = mid - begin + 1;
    int const subArrayRight = end - mid;

    C *leftArray = new C[subArrayLeft];
    C *rightArray = new C[subArrayRight];

    //copy array
    for (int i = 0; i <= subArrayLeft; i++)
    {
        leftArray[i] = arr[begin + i];
    }
    for (int i = mid + 1; i <= end; i++)
    {
        rightArray[i - mid - 1] = arr[i];
    }

    int leftIndex = 0;
    int rightIndex = 0;

    int mergeIndex = begin;
    while (leftIndex < subArrayLeft && rightIndex < subArrayRight)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            arr[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while (leftIndex < subArrayLeft)
    {
        arr[mergeIndex] = leftArray[leftIndex];
        mergeIndex++;
        leftIndex++;
    }
    while (rightIndex < subArrayRight)
    {
        arr[mergeIndex] = rightArray[rightIndex];
        mergeIndex++;
        rightIndex++;
    }
}

template <class T>
void mergeSort(T arr[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
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
        for (int i = 0; i < length; i++)
        {
            cout << list[i];
            if (i != length - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
        delete[] list;
    }
}