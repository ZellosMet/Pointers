#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], int n);
void PushFront(int *&arr, int &n);
void PushBack(int *&arr, int &n);
void Insert(int *&arr, int &n);
void PopFront(int *&arr, int &n);
void PopBack(int *&arr, int &n);
void Erase(int *&arr, int &n);

void FillRandMatrix(int **arr, const int rows, const int cols);
void PrintMatrix(int **arr, const int rows, const int cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef DYNAMIC_MEMORY_1
	int n;
	int& rn = n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	PushFront(arr, rn);
	Print(arr, n);
	PushBack(arr, rn);
	Print(arr, n);
	Insert(arr, rn);
	Print(arr, n);
	PopFront(arr, rn);
	Print(arr, n);
	PopBack(arr, rn);
	Print(arr, n);
	Erase(arr, rn);
	Print(arr, n);

	delete[] arr;
#endif 

#ifdef DYNAMIC_MEMORY_2

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arr[i] = new int[cols];
	}

	FillRandMatrix(arr, rows, cols);
	PrintMatrix(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

#endif 
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRandMatrix(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void PrintMatrix(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[ " << arr[i] << " ]" << "  ";
	}
	cout << endl;
}

void PushFront(int *&arr, int &n)
{
	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
}

void PushBack(int *&arr, int &n)
{
	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	int* buffer = new int[++n];	
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}	
	delete[] arr;	
	arr = buffer;
	arr[n-1] = value;	
}

void Insert(int *&arr, int &n)
{
	int value, ins_element;
	cout << "Введите порядковый номер элемента для добавления: "; cin >> ins_element;
	cout << "Введите добовляемое значение: "; cin >> value;
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if(i > ins_element-1) buffer[i] = arr[i-1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[ins_element-1] = value;
}

void PopFront(int*& arr, int& n)
{
	cout << "Был удалён первый элемент \n";
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
}

void PopBack(int *&arr, int &n)
{
	cout << "Был удалён последний элемент\n";
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

void Erase(int*& arr, int& n)
{
	int ers_element;
	cout << "Введите порядковый номер элемента для удаления: "; cin >> ers_element;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i >= ers_element-1) 
		buffer[i] = arr[i+1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

