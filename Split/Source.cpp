#include<iostream>
#include<time.h>
using namespace std;

void FillRand(int arr[], const int size); //Функция заполнения массива
void Print(int arr[], const int size); // Функция вывода массива
void Size_Calc(int arr[], const int size, int &reven, int &rodd); //Функция расчёта размера массивов
void Element_Sorting(int base_arr[], const int size, int even_arr[], int odd_arr[]); //Функция сортировки элементов по массивам

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int size, even, odd;
	int &reven = even = 0, &rodd = odd = 0;

	cout << "Введите размер массива: "; cin >> size;
	int *base_array = new int[size];

	cout << "\nСегенерированный массив\n";
	FillRand(base_array, size);
	Print(base_array, size);
	Size_Calc(base_array, size, reven, rodd);

	int *even_arr = new int[even];
	int *odd_arr = new int[odd];
	Element_Sorting(base_array, size, even_arr, odd_arr);

	cout << "\n\nМассив чётных элементов\n";
	Print(even_arr, even);
	cout << "\n\nМассив нечётных элементов\n";
	Print(odd_arr, odd);
	cout << endl;

	delete[] odd_arr;
	delete[] even_arr;
	delete[] base_array;
}

void FillRand(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[ " << arr[i] << " ] " << "\t";
	}
}

void Size_Calc(int arr[], const int size, int &reven, int &rodd)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0) reven++;
		else rodd++;
	}
}

void Element_Sorting(int base_arr[], const int size, int even_arr[], int odd_arr[])
{
	int j = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		if (base_arr[i] % 2 == 0)
		{
			even_arr[j] = base_arr[i]; 
			j++;
		}
		else
		{
			odd_arr[k] = base_arr[i]; 
			k++;
		}
	}
}