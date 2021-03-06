/* 7.Напишите эффективную функцию, выписывающую из массива длины n все элементы, у которых количество двоек в 
троичной записи меньше k. Функция должна возвращать общее количество двоек в троичной записи всех чисел массива.
*/

#include "pch.h"
#include <iostream>
using namespace std;

int rar(int* a, int b, int c)
{
	int abc = 0;
	for (int i = 0; i < b; i++)
	{
		int nyc = 0, ac = a[i];
		while (ac > 1)
		{
			if ((ac % 3) == 2) { abc++; nyc++; };
			ac /= 3;
		};
		if (nyc < c) { cout << a[i] << " "; };
	};
	cout << '\n';
	return abc;
}


int main()
{
	int n, k;
	cout << "N: ";
	cin >> n;
	cout << "K: ";
	cin >> k;

	int* ali = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Numbers: ";
		cin >>ali[i];
	};

	cout << rar(ali, n, k);
	return 0;
}