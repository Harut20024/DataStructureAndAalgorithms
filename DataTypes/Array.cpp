#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));


//dynamic array
    int *arr = new int[4]{1, 2, 4, 5};
    cout << " dynamic array" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i << "-st number is: " << arr[i] << endl;
    }


//static array
    int arr1[4];
    int size = sizeof(arr1) / sizeof(arr1[0]);
    cout << "size of static arr is: " << size << endl;
    for (int i = 0; i < 4; i++)
    {
        arr1[i] = rand() % 10;
    }

    cout << " static array" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i << "-st number is: " << arr1[i] << endl;
    }





    delete[] arr;
    return 0;
}
