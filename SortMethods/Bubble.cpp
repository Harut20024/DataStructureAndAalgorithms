#include <iostream>
using namespace std;

template <typename T>
void BubbleSort(T arr[], int n)
{
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    int arr[] = {1213232, 1, 23, 44, 12, 435, 123, 3, 21212, 32323};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
