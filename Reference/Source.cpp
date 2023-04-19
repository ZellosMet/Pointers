#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	int a = 2;
	int& ra = a;
	cout << a << endl;
	ra += 3;
	cout << a << endl;
}
