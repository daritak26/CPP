// Напишите программу, вычисляющую биномиальный коэффициент из n по к. В программе нельзя использовать числа, превышающие итоговое значение. 

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int num; // размер массива
	cout << "Enter integer value: ";
	cin >> num; // получение от пользователя размера массива

	int *p_darr = new int[num]; // Выделение памяти для массива
	for (int i = 0; i < num; i++) {
		// Заполнение массива и вывод значений его элементов
		//p_darr[i] = i;
		cout << "Enter integer elements";
		cin >> p_darr[i];
		cout << "Value of " << i << " element is " << p_darr[i] << endl;
	}
	delete[] p_darr; // очистка памяти
	return 0;



}

