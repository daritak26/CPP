//6) Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей 
 
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int num;                              // Размер массива
	cout << "Enter integer value: ";
	cin >> num;                            // Получение от пользователя размера массива
	cout << "Enter elements: ";

	int *p_darr = new int[num];           // Выделение памяти для массива
	for (int i = 0; i < num; i++) {
		cin >> p_darr[i];
		int a = 0;
		for (int b = 1; b <= p_darr[i]; b++) {
			if (p_darr[i] % b == 0)
				a++;
		}

		if (a >= 5)
			cout << p_darr[i] << " ";
	}

	delete[] p_darr;                    // Очистка памяти
	return 0;
}

