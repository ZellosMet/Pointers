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
void Clear(int **arr, const int rows, const int cols);
void FillRandMatrix(int **arr, const int rows, const int cols);
void PrintMatrix(int **arr, const int rows, const int cols);

int **PushRowBack(int **arr, int &rows, const int cols);
int **PushRowFront(int **arr, int &rows, const int cols);
int **InsertRow(int **arr, int &rows, const int cols, int const index);
int **PopRowBack(int **arr, int &rows, const int cols);
int **PopRowFront(int **arr, int &rows, const int cols);
int **EraseRow(int **arr, int &rows, const int cols, int const index);
int **PushColsBack(int **arr, const int rows, int &cols);
int **PushColsFront(int **arr, const int rows, int &cols);
int **InsertCols(int **arr, const int rows, int &cols, int const index);
int **PopColsBack(int **arr, const int rows, int &cols);
int **PopColsFront(int **arr, const int rows, int &cols);
int **EraseCols(int **arr, const int rows, int &cols, int const index);

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
	int rows, cols, index;

	cout << "Введите размер массива(строки и колонки): "; cin >> rows >> cols;
	int **arr = Allocate(rows, cols);

	FillRandMatrix(arr, rows, cols);
	PrintMatrix(arr, rows, cols);

	arr = PushRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PushRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки: "; cin >> index;
	arr = InsertRow(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	arr = PopRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PopRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки: "; cin >> index;
	arr = EraseRow(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	arr = PushColsBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PushColsFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки: "; cin >> index;
	arr = InsertCols(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	arr = PopColsBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PopColsFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки: "; cin >> index;	
	arr = EraseCols(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);

	Clear(arr, rows, cols);
#endif 
}
//Реализвция для матриц
void FillRandMatrix(int **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void PrintMatrix(int **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int **Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows]{};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]{};
	}
	return arr;
}
void Clear(int **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int **PushRowFront(int **arr, int &rows, const int cols)
{
	int **buffer = Allocate(rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i+1][j] = arr[i][j];
	Clear(arr, rows++, cols);
	return buffer;
}
int **PushRowBack( int **arr, int &rows, const int cols)
{
	int **buffer = Allocate(rows+1, cols);	
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i][j];
	Clear(arr, rows++, cols);
	return buffer;
}
int **InsertRow(int **arr, int &rows, const int cols, int const index)
{
	int **buffer = Allocate(rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) i>=index ? buffer[i + 1][j] = arr[i][j] : buffer[i][j] = arr[i][j];
	Clear(arr, rows++, cols);
	return buffer;
}
int **PopRowFront(int **arr, int &rows, const int cols)
{
	int **buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i+1][j];
	Clear(arr, rows, cols);
	return buffer;
}
int **PopRowBack(int **arr, int &rows, const int cols)
{
	int **buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols);
	return buffer;
}
int **EraseRow(int **arr, int &rows, const int cols, int const index)
{
	int **buffer = Allocate(--rows, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) i >= index? buffer[i][j] = arr[i+1][j] : buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols);
	return buffer;
}
int **PushColsFront(int **arr, const int rows, int& cols)
{
	int **buffer = Allocate(rows, cols + 1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j+1] = arr[i][j];
	Clear(arr, rows, cols++);
	return buffer;
}
int **PushColsBack(int **arr, const int rows, int &cols)
{
	int **buffer = Allocate(rows, cols+1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols++);
	return buffer;
}
int **InsertCols(int **arr, const int rows, int &cols, int const index)
{
	int **buffer = Allocate(rows, cols + 1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) j >= index? buffer[i][j + 1] = arr[i][j] : buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols++);
	return buffer;
}
int **PopColsFront(int **arr, const int rows, int &cols)
{
	int **buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i][j+1];
	Clear(arr, rows, cols);
	return buffer;
}
int **PopColsBack(int **arr, const int rows, int &cols)
{
	int **buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols);
	return buffer;
}
int **EraseCols(int **arr, const int rows, int &cols, int const index)
{
	int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) j >= index ? buffer[i][j] = arr[i][j+1] : buffer[i][j] = arr[i][j];
	Clear(arr, rows, cols);
	return buffer;
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