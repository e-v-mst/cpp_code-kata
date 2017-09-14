#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(int *arrayPtr, int length) // сортировка вставками
{
    int temp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter-1;
        cout << item << "  ";
        while(item >= 0 && arrayPtr[item] > temp)
        {
            arrayPtr[item + 1] = arrayPtr[item];
            arrayPtr[item] = temp;
            --item;
        }
    }
}

int main()
{
    fstream infile ("input.txt");
    if (!infile)
    {
        cout << "can't read file input.txt" << endl;
        return EXIT_FAILURE;
    }

    int size_array = 0;
    infile  >> size_array;

    int sorted_array[size_array];

    int a = 0, i = 0;
    while (infile >> a) {
         sorted_array[i] = a;
         ++i;
    }

    insertionSort(sorted_array, size_array);

    ofstream outfile ("output.txt");
    for (int counter = 0; counter < size_array; counter++)
    {
        //cout << sorted_array[counter] << "  ";
        outfile << sorted_array[counter] << "  ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}


