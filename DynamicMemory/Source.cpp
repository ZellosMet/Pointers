#include<iostream>
using namespace std;
//Функции для линейного массива
void FillRand(int arr[], const int n);
void Print(int arr[], int n);
int *PushFront(int *arr, int &n, const int value);
int *PushBack(int *arr, int &n, const int value);
int *Insert(int *arr, int &n, const int index, const int value);
int *PopFront(int *arr, int &n);
int *PopBack(int *arr, int &n);
int *Erase(int *arr, int &n, const int index);
//Функции для матриц
int **Allocate(const int rows, const int cols);
void Clear(int **arr, const int rows);
void FillRandMatrix(int **arr, const int rows, const int cols);
void PrintMatrix(int **arr, const int rows, const int cols);

void PushRowBack(int **&arr, int &rows, const int cols);
void PushRowFront(int **&arr, int &rows, const int cols);
void InsertRow(int **&arr, int &rows, const int cols, int const index);
void PopRowBack(int **&arr, int &rows, const int cols);
void PopRowFront(int **&arr, int &rows, const int cols);
void EraseRow(int **&arr, int &rows, const int cols, int const index);
void PushColsBack(int **arr, const int rows, int &cols);
void PushColsFront(int **arr, const int rows, int &cols);
void InsertCols(int **arr, const int rows, int &cols, int const index);
void PopColsBack(int **arr, const int rows, int &cols);
void PopColsFront(int **arr, const int rows, int &cols); //???
void EraseCols(int **arr, const int rows, int &cols, int const index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef DYNAMIC_MEMORY_1
	int n, index, value;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = PushBack(arr, n, value);
	Print(arr, n);
	cout << "Введите порядковый номер элемента для добавления: "; cin >> index;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = Insert(arr, n, index, value);
	Print(arr, n);
	cout << "Был удалён первый элемент \n";
	arr = PopFront(arr, n);
	Print(arr, n);
	cout << "Был удалён последний элемент\n";
	arr = PopBack(arr, n);
	Print(arr, n);
	cout << "Введите порядковый номер элемента для удаления: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif 

#ifdef DYNAMIC_MEMORY_2
	int rows = 3, cols = 4, index;

	cout << "Введите размер массива(строки и колонки): "; cin >> rows >> cols;
	int **arr = Allocate(rows, cols);

	FillRandMatrix(arr, rows, cols);
	PrintMatrix(arr, rows, cols);

	PushRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	PushRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки для добовления: "; cin >> index;
	InsertRow(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	PopRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	PopRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки для удаления: "; cin >> index;
	EraseRow(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	PushColsBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	PushColsFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс столбца для добавления: "; cin >> index;
	InsertCols(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	PopColsBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	PopColsFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс столбца для удаления: "; cin >> index;	
	EraseCols(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);

	Clear(arr, rows);
#endif 
}
//Реализвция для матриц
void FillRandMatrix(int **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
}
void PrintMatrix(int **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << *(*(arr + i) + j) << "\t";
		cout << endl;
	}
	cout << endl;
}
int **Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows]{};
	for (int i = 0; i < rows; i++) arr[i] = new int[cols]{};
	return arr;
}
void Clear(int **arr, const int rows)
{
	for (int i = 0; i < rows; i++) 
		delete[] arr[i];
	delete[] arr;
}

void PushRowFront(int **&arr, int &rows, const int cols)
{
	int** buffer = Allocate(++rows, cols);
	for (int i = 0; i < rows - 1; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
}
void PushRowBack(int **&arr, int &rows, const int cols)
{
	int **buffer = Allocate(++rows, cols);	
	for (int i = 0; i < rows-1; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[rows-1] = new int[cols]{};
}
void InsertRow(int **&arr, int &rows, const int cols, int const index)
{
	int** buffer = Allocate(++rows, cols);
	for (int i = 0; i < rows - 1; i++) i >= index ? buffer[i + 1] = arr[i] : buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols] {};
}
void PopRowFront(int **&arr, int &rows, const int cols)
{
	int** buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}
void PopRowBack(int **&arr, int &rows, const int cols)
{
	int** buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
}
void EraseRow(int **&arr, int &rows, const int cols, int const index)
{
	int** buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) i >= index ? buffer[i] = arr[i+1] : buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
}
void PushColsFront(int **arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int *buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void PushColsBack(int **arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void InsertCols(int **arr, const int rows, int &cols, int const index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) j >= index ? buffer[j + 1] = arr[i][j] : buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void PopColsFront(int **arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		int *buffer = new int[cols - 1] {};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void PopColsBack(int **arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void EraseCols(int **arr, const int rows, int &cols, int const index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols-1; j++) 
			j >= index ? buffer[j] = arr[i][j+1] : buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
//Реализация для линеек
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
		cout << "[ " << arr[i] << " ]" << "  ";
	}
	cout << endl;
}
int *PushFront(int *arr, int &n, const int value)
{
	int *buffer = new int[++n];
	for (int i = 0; i < n; i++) buffer[i+1] = arr[i];
	buffer[0] = value;
	delete[] arr;
	return buffer;
}
int *PushBack(int *arr, int &n, const int value)
{	
	int *buffer = new int[++n];	
	for (int i = 0; i < n; i++) 
		buffer[i] = arr[i];
	buffer[n-1] = value;
	delete[] arr;	
	return buffer;
}
int *Insert(int *arr, int &n, const int index, const int value)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++) i >= index? buffer[i] = arr[i - 1] : buffer[i] = arr[i];
	buffer[index] = value;
	delete[] arr;
	return buffer;
}
int *PopFront(int *arr, int &n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
int *PopBack(int *arr, int &n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int *Erase(int *arr, int &n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) i >= index ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}