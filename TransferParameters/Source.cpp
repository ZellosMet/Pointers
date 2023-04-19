#include<iostream>

using namespace std;

void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "ru");

	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	Exchange(a, b);
	cout << a << "\t" << b << endl;

}

void Exchange(int a, int b)
{
	int buf = a;
	a = b;
	b = buf;

}