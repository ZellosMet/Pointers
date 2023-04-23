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

#define Lesson
#define HomeWork


void main()
{
	setlocale(LC_ALL, "ru");

#ifdef Lesson
	int n;
	int& rn = n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	//PushFront(arr, rn);
	//Print(arr, n);
	//PushBack(arr, rn);
	//Print(arr, n);
	Insert(arr, rn);
	Print(arr, n);
	//PopBack(arr, rn);
	//Print(arr, n);
	//PopFront(arr, rn);
	//Print(arr, n);
	//Erase(arr, rn);
	//Print(arr, n);

	delete[] arr;
#endif

#ifdef HomeWork




#endif // HomeWork

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
		cout << "[ " << arr[i] << " ]" << "\t";
	}
	cout << endl;
}


void PushFront(int *&arr, int &n)
{
	int value;
	cout << "¬ведите добовл€емое значение: "; cin >> value;
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
	cout << "¬ведите добовл€емое значение: "; cin >> value;
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
	cout << "¬ведите пор€дковый номер элемента дл€ добавлени€: "; cin >> ins_element;
	cout << "¬ведите добовл€емое значение: "; cin >> value;
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if(i > ins_element) buffer[i] = arr[i-1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[ins_element] = value;
}

void PopFront(int*& arr, int& n)
{
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
	cout << "¬ведите пор€дковый номер элемента дл€ добавлени€: "; cin >> ers_element;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i > ers_element) 
		buffer[i] = arr[i+1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}