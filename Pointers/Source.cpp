#include<iostream>

using namespace std;

//#define POINTER_BASICS
//#define POINTER_BASICS_2
#define HOME_WORLD_1

void main()
{

	setlocale(LC_ALL, "ru");
	const int n = 5;
	int arr[n] = { 3, 5, 6, 13, 21 };

#ifdef POINTER_BASICS

	int a = 2;
	int *pa = &a;

	cout << a << endl; // ����� ���������� "a"
	cout << &a << endl; // ����� ������ � ����� �� ����� ���������� "�"
	cout << pa << endl; // ����� ������ ���������� "�", ���������� � ��������� "��"
	cout << *pa << endl; // ������������� � ����� ���������� "�" �� ������

#endif

#ifdef POINTER_BASICS_2


	cout << arr << endl;
	cout << *arr << endl;
	cout << &arr[0] << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << endl;
	}

#endif 

#ifdef HOME_WORLD_1

	cout << "������ ����� �������� �������� �������\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << endl;
	cout << "����� ��������� ������� � ������� ���������� ����������\n";
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

#endif

}