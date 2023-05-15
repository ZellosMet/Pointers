#include<iostream>
using namespace std;
//Функции для линейного массива
void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
template <typename T> void Print(T arr[], const int n);
template <typename T> T *PushFront(T *arr, int &n, const T value);
template <typename T> T *PushBack(T *arr, int &n, const T value);
template <typename T> T *Insert(T *arr, int &n, const int index, const T value);
template <typename T> T *PopFront(T *arr, int &n);
template <typename T> T *PopBack(T *arr, int &n);
template <typename T> T *Erase(T *arr, int &n, const int index);

//Функции для матриц
void FillRandMatrix(int **arr, const int rows, const int cols);
void FillRandMatrix(double **arr, const int rows, const int cols);
void FillRandMatrix(char **arr, const int rows, const int cols);

template <typename T> T **Allocate(const int rows, const int cols); //???

int **Allocate(const int rows, const int cols);
template <typename T> void PrintMatrix(T **arr, const int rows, const int cols);
template <typename T> void Clear(T **arr, const int rows);
template <typename T> T **PushRowBack(T **arr, int &rows, const int cols);
template <typename T> T **PushRowFront(T **arr, int &rows, const int cols);
template <typename T> T **InsertRow(T **arr, int &rows, const int cols, int const index);
template <typename T> T **PopRowBack(T **arr, int &rows, const int cols);
template <typename T> T **PopRowFront(T **arr, int &rows, const int cols);
template <typename T> T **EraseRow(T **arr, int &rows, const int cols, int const index);
template <typename T> void PushColsBack(T **arr, const int rows, int &cols);
template <typename T> void PushColsFront(T **arr, const int rows, int &cols);
template <typename T> void InsertCols(T **arr, const int rows, int &cols, int const index);
template <typename T> void PopColsBack(T **arr, const int rows, int &cols);
template <typename T> void PopColsFront(T **arr, const int rows, int &cols);
template <typename T> void EraseCols(T **arr, const int rows, int &cols, int const index);

#define delimiter "\n------------------------------------\n"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef DYNAMIC_MEMORY_1
	int n, index;
	//int value;
	//double value;
	char value;
	cout << "Введите размер массива: "; cin >> n;
	//int *arr = new int[n];
	//double *arr = new double[n];
	char* arr = new char[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << "Введите первое добовляемое значение : "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);
	cout << "Введите последнее добовляемое значение: "; cin >> value;
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
	/*int **arr = new int *[rows]{};
	for (int i = 0; i < rows; i++) arr[i] = new int[cols] {};*/

	//double **arr = Allocate(rows, cols);
	//int **arr = new int *[rows]{};
	//for (int i = 0; i < rows; i++) arr[i] = new double[cols] {};

	//char **arr = Allocate(rows, cols);
	//char** arr = new char* [rows] {};
	//for (int i = 0; i < rows; i++) arr[i] = new char[cols] {};

	FillRandMatrix(arr, rows, cols);
	PrintMatrix(arr, rows, cols);

	arr = PushRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PushRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки для добовления: "; cin >> index;
	arr = InsertRow(arr, rows, cols, index);
	PrintMatrix(arr, rows, cols);
	arr = PopRowBack(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	arr = PopRowFront(arr, rows, cols);
	PrintMatrix(arr, rows, cols);
	cout << "Введите индекс строки для удаления: "; cin >> index;
	arr = EraseRow(arr, rows, cols, index);
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
void FillRandMatrix(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
}
void FillRandMatrix(double **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
	{
		arr[i][j] = rand() % 10000; 
		arr[i][j] /= 100;
	}
}
void FillRandMatrix(char **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = 65 + rand() % 26;
}
template <typename T> void PrintMatrix(T **arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << "[ " << *(*(arr + i) + j) << " ] ";
		cout << endl;
	}
	cout << delimiter;
}
int **Allocate(const int rows, const int cols)
{
	int **arr = new int *[rows] {};
	for (int i = 0; i < rows; i++) arr[i] = new int[cols] {};
	return arr;
}
template <typename T> T **Allocate(const int rows, const int cols) //????
{
	T **arr = new T *[rows] {};
	for (int i = 0; i < rows; i++) arr[i] = new T[cols] {};
	return arr;
}
template <typename T> void Clear(T **arr, const int rows)
{
	for (int i = 0; i < rows; i++) 
		delete[] arr[i];
	delete[] arr;
}
template <typename T > T** PushRowFront(T** arr, int& rows, const int cols)
{
	T **buffer = new T *[rows + 1];
	for (int i = 0; i < rows; i++)

	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols] {};
	rows++;
	return arr;
}
template <typename T > T **PushRowBack(T **arr, int &rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template <typename T > T**InsertRow(T **arr, int &rows, const int cols, int const index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		i >= index ? buffer[i + 1] = arr[i] : buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[cols] {};
	rows++;
	return arr;
}
template <typename T > T **PopRowFront(T **arr, int &rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows-1; i++) 
	{	
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T > T **PopRowBack(T **arr, int &rows, const int cols)
{
	T ** buffer = new T* [rows - 1];
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T > T **EraseRow(T **arr, int& rows, const int cols, int const index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows-1; i++)
	{	
		i >= index ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T> void PushColsFront(T **arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T *buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void PushColsBack(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void InsertCols(T **arr, const int rows, int &cols, int const index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) j >= index ? buffer[j + 1] = arr[i][j] : buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void PopColsFront(T **arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		T *buffer = new T[cols - 1] {};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T> void PopColsBack(T **arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T> void EraseCols(T **arr, const int rows, int &cols, int const index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = 65 + rand() % 26;
	}
}
template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[ " << arr[i] << " ]" << "  ";
	}
	cout << endl;
}
template <typename T> T* PushFront(T *arr, int &n, const T value)
{
	T *buffer = new T[++n];
	for (int i = 0; i < n; i++) buffer[i+1] = arr[i];
	buffer[0] = value;
	delete[] arr;
	return buffer;
}
template <typename T> T *PushBack(T *arr, int &n, const T value)
{	
	T *buffer = new T[++n];	
	for (int i = 0; i < n; i++) 
		buffer[i] = arr[i];
	buffer[n-1] = value;
	delete[] arr;	
	return buffer;
}
template <typename T> T *Insert(T *arr, int &n, const int index, const T value)
{
	T *buffer = new T[++n];
	for (int i = 0; i < n; i++) i >= index? buffer[i] = arr[i - 1] : buffer[i] = arr[i];
	buffer[index] = value;
	delete[] arr;
	return buffer;
}
template <typename T> T *PopFront(T *arr, int &n)
{
	T *buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
template <typename T> T *PopBack(T *arr, int &n)
{
	T *buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template <typename T> T *Erase(T *arr, int &n, const int index)
{
	T *buffer = new T[--n];
	for (int i = 0; i < n; i++) i >= index ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}