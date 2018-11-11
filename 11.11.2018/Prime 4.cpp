// 4) Напишите программу, находящую сумму простых элементов массива. 


#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int num;                          // Размер массива
	int sum = 0;
	cout << "Enter integer value: ";
	cin >> num;                       // Получение от пользователя размера массива

	int *p_darr = new int[num];       // Выделение памяти для массива
	cout << "Elements: ";
	for (int i = 0; i < num; i++) {

		cin >> p_darr[i];

		if (p_darr[i] == 1)
			sum += p_darr[i];
		if (p_darr[i] == 2)
			sum += p_darr[i];
		if (p_darr[i] == 3)
			sum += p_darr[i];
		
		for (int b = 2; b < p_darr[i] - 1; b++) {
			if (p_darr[i] % b != 0)
				sum += p_darr[i];
			cout << sum << endl;
			break;
		}
		
		
	}
	cout << "sum: " << sum;
	delete[] p_darr;                   // Очистка памяти
	return 0;
}
