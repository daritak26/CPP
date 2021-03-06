// 8) Напишите две функции, находящие приближенное значение квадратного и кубического корня. В программе не должны использоваться 
// математические библиотеки.

#include "pch.h"
#include <iostream>
using namespace std;


double radical2(int x) {   // Функция для нахождения квадратного корня
	double z = 0;
	while (z*z < x) {
		z += 0.01;
	}

	return z;
}

double radical3(int y) {     // Функция для нахождения кубического корня
	double z = 0;
	while (z*z*z <= y) {
		z += 0.01;
	}

	return z;
}


int main()
{
	int a;           // Пример
	cin >> a;
	double b, w;
	b = radical2(a);
	w = radical3(a);
	cout << b << endl << w;
	return 0;

}

