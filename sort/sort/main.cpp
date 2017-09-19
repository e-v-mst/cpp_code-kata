#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(long int *arrayPtr, long int *indexArray, long int length) // сортировка вставками
{
    int temp, item;

    indexArray[0] = 1;

    for (int i = 1; i < length; i++)
    {
        temp = arrayPtr[i];
        item = i - 1;

        while (item >= 0 && arrayPtr[item] > temp)
        {
            arrayPtr[item + 1] = arrayPtr[item];
            arrayPtr[item] = temp;
            item--;
        }

        indexArray[i] = item + 2;
    }
}

int main()
{
    fstream inFile("input.txt");

    if (!inFile)
    {
        cout << "can't read file input.txt" << endl;
        return EXIT_FAILURE;
    }

    long int size_array = 0;
    inFile >> size_array;

    long int *sort_array = new long int[size_array];
    long int *index_array = new long int[size_array];


    int i = 0;
    while (!inFile.eof()) {
        inFile >> sort_array[i];
        ++i;
    }


    insertionSort(sort_array, index_array, size_array);

    ofstream  outFile("output.txt");

    for (int i = 0; i < size_array; ++i)
        outFile << index_array[i] << " ";

    outFile << "\n";

    for (int i = 0; i < size_array; ++i)
        outFile << sort_array[i] << " ";


    delete[] index_array;
    delete[] sort_array;

    return EXIT_SUCCESS;
}



