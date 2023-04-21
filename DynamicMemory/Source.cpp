#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "ru");
	int n;

	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);	
	//Увеличение элементов м ассива
	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	//1) Создаём буферный массив нужного размера ()
	int* buffer = new int[n + 1];
	//2) Копируем все значения в буферный массив
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем массив
	delete[] arr;
	//4) Подменяем адрес исходного массива на новый
	arr = buffer;
	//5) Добавить новое значение
	arr[n] = value;
	//6) После добовление элемента в массив количество его элементов увеличивается на 1
	n++;
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}