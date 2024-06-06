#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int startSize = 400;
    const int totalNumbers = 4000000;
    int iterations = 0;
    int tempSize = startSize;

    while (tempSize < totalNumbers)
    {
        tempSize *= 2;
        iterations++;
    }

    //// step 1. create random numbers file

    ofstream fileWrite;
    fileWrite.open("task.txt");

    for (int i = 0; i < totalNumbers; i++)
    {
        int random = rand();
        fileWrite << random << endl;
    }
    fileWrite.close();

    ////step 2. devide file into 400 numbers

    ifstream readRandomFile("task.txt");
    ofstream WriteOrderedfile;
    WriteOrderedfile.open("devideArr.txt");
    int num;
    int count = 0;
    if (readRandomFile)
    {
        while (readRandomFile >> num)
        {
            if (count == 400)
            {
                WriteOrderedfile << "]" << endl;
                count = 0;
            }
            WriteOrderedfile << num << endl;
            count++;
        }
    }
    WriteOrderedfile.close();
    readRandomFile.close();

    ////step 3.  filter 400 numbers of each array

    ifstream readFile("devideArr.txt");
    ofstream file("sortedArr.txt");

    int *arr = new int[startSize];
    int i = 0;
    string line;

    while (getline(readFile, line))
    {
        if (line == "]")
        {
            sort(arr, arr + i);
            for (int j = 0; j < i; j++)
            {
                file << arr[j] << endl;
            }
            file << "]" << endl;
            i = 0;
        }
        else
        {
            if (!line.empty())
            {
                arr[i++] = stoi(line);
            }
        }
    }

    delete[] arr;
    readFile.close();
    file.close();

    //// step 4. filter all pices of file to one filtred file

    string inputFile = "sortedArr.txt";
    string outputFile = "tempSorted.txt";
    for (int i = 0; i < iterations; ++i)
    {
        ifstream readFileSort(inputFile);
        ofstream fileSort(outputFile);

        string line;
        int *arr1 = new int[startSize];
        int *arr2 = new int[startSize];
        int *arr3 = new int[startSize * 2];
        int arr1Size = 0, arr2Size = 0, totalProcessed = 0;

        bool dataProcessed = false;

        while (getline(readFileSort, line))
        {
            if (line.empty() || line == "]")
                continue;

            if (totalProcessed < startSize)
            {
                arr1[arr1Size++] = stoi(line);
            }
            else
            {
                arr2[arr2Size++] = stoi(line);
            }
            totalProcessed++;

            if (totalProcessed == startSize * 2)
            {
                merge(arr1, arr1Size, arr2, arr2Size, arr3);
                for (int j = 0; j < arr1Size + arr2Size; j++)
                {
                    fileSort << arr3[j] << endl;
                }
                dataProcessed = true;
                totalProcessed = 0;
                arr1Size = 0;
                arr2Size = 0;
            }
        }

        if (dataProcessed)
        {
            swap(inputFile, outputFile);
        }

        startSize *= 2;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        readFileSort.close();
        fileSort.close();
    }

    if (inputFile != "finalResult.txt")
    {
        rename(inputFile.c_str(), "finalResult.txt");
        remove(outputFile.c_str());
    }

    return 0;
}