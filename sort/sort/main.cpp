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
        item = counter-1; // запоминаем индекс предыдущего элемента массива
        while(item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
            arrayPtr[item] = temp;
            item--;
        }
    }
}

int main()
{

       int size_array = 10;


       int sorted_array[10] = {1, 8, 4, 2, 3, 7, 5, 6, 9, 0};

       insertionSort(sorted_array, size_array);

       for (int counter = 0; counter < size_array; counter++)
       {
           cout << sorted_array[counter] << "  ";
       }
       cout << "\n";
       delete [] sorted_array;
       system("pause");

       return 0;
}


