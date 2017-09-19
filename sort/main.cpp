#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(long int *arrayPtr, long int *indexArray, long int length) // сортировка вставками
{
    int temp, item;

    indexArray[0] = 1;

    for (int i = 1; i < length; i++)
    {
<<<<<<< HEAD
        temp = arrayPtr[i];
        item = i - 1;

        while (item >= 0 && arrayPtr[item] > temp)
=======
        temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter-1;
        cout << item << "  ";
        while(item >= 0 && arrayPtr[item] > temp)
>>>>>>> c898d7e124245c3077bfb8c7870b9c40adae8a77
        {
            arrayPtr[item + 1] = arrayPtr[item];
            arrayPtr[item] = temp;
            --item;
        }

        indexArray[i] = item + 2;
    }
}

int main()
{
<<<<<<< HEAD
    fstream inFile("input.txt");

    if (!inFile)
=======
    fstream infile ("input.txt");
    if (!infile)
>>>>>>> c898d7e124245c3077bfb8c7870b9c40adae8a77
    {
        cout << "can't read file input.txt" << endl;
        return EXIT_FAILURE;
    }

<<<<<<< HEAD
    long int size_array = 0;
    inFile >> size_array;

    long int *sort_array = new long int[size_array];
    long int *index_array = new long int[size_array];
=======
    int size_array = 0;
    infile  >> size_array;

    int sorted_array[size_array];
>>>>>>> c898d7e124245c3077bfb8c7870b9c40adae8a77

    int a = 0, i = 0;
    while (infile >> a) {
         sorted_array[i] = a;
         ++i;
    }

<<<<<<< HEAD
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

=======
    insertionSort(sorted_array, size_array);

    ofstream outfile ("output.txt");
    for (int counter = 0; counter < size_array; counter++)
    {
        //cout << sorted_array[counter] << "  ";
        outfile << sorted_array[counter] << "  ";
    }

    cout << endl;

>>>>>>> c898d7e124245c3077bfb8c7870b9c40adae8a77
    return EXIT_SUCCESS;
}



