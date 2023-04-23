#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], int cursor[], const int n, int lc_crs, int step);
void Insert(int *&arr, int &n, int lc_crs);
void Erase(int *&arr, int &n, int &lc_crs);

#define MOVE_LEFT 75  
#define MOVE_RIGHT 77
#define FIRST_STEP 49
#define LAST_STEP 57
#define ADD 43
#define REMOVE 45
#define ESC 27

void main()
{
	setlocale(LC_ALL, "ru");

	int n, control, step = 1, local_cursor=0, &rn = n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	int* cursor = new int[n] {};

	FillRand(arr, n);
	Print(arr, cursor, n, local_cursor, step);	

	do
	{
		control = _getch();
		if (control >= FIRST_STEP && control <= LAST_STEP)
		{
			step = (++control) - FIRST_STEP;
			Print(arr, cursor, n, local_cursor, step);
		}
		switch (control)
		{
		case MOVE_RIGHT: (local_cursor+step <= n-1 ? local_cursor = local_cursor + step : local_cursor = n-1); Print(arr, cursor, n, local_cursor, step); break;
		case MOVE_LEFT: (local_cursor-step >= 0 ? local_cursor = local_cursor - step : local_cursor = 0); Print(arr, cursor, n, local_cursor, step); break;
		case ADD: Insert(arr, n, local_cursor); Print(arr, cursor, n, local_cursor, step); break;
		case REMOVE: Erase(arr, n, local_cursor); Print(arr, cursor, n, local_cursor, step); break;
		}
	} while (control != ESC);

	delete[] arr;
	delete[] cursor;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], int cursor[], const int n, int lc_crs, int step)
{
	system("cls");
	cout << "УПРАВЛЕНИЕ: Курсором, с помощью стрелочек, выбирается элемент. Шаг движения курсора регулируется нажатием клавиш 1-9.\n";
	cout << "Добавление элемента осуществляется нажатием клавиши \"+\". Удаление элемента осуществляется нажатием клавиши \"-\".\n";
	cout << "ESC - Выход\n\n";
	cout << "Установлен шаг: " << step << endl << endl;
	setlocale(LC_ALL, "C");
	for (int i = 0; i < n; i++)
	{
		if (i==lc_crs)
		{
			if (arr[i]<10) cout << "  " << (char)31 << "    ";
			else if (arr[i] >= 10 || arr[i] < 100) cout << "   " << (char)31 << "    ";
		}
		else
		{
			if (arr[i] < 10) cout << "  " << " " << "    ";
			else if (arr[i] >= 10 || arr[i] < 100) cout << "   " << " " << "    ";
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[ " << arr[i] << " ]  ";
	}
	setlocale(LC_ALL, "ru");
}

void Insert(int *&arr, int &n, int lc_crs)
{
	int value;
	cout << "\nВведите добовляемое значение: "; cin >> value;
	int *buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if(i > lc_crs) buffer[i] = arr[i-1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[lc_crs] = value;
}

void Erase(int *&arr, int &n, int &lc_crs)
{
	int *buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i >= lc_crs) 
		buffer[i] = arr[i+1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	if (lc_crs >= n) lc_crs = n-1;
}