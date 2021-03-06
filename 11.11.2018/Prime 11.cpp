/*
11) Напишите процедуру, удаляющую из динамически выделенного массива
максимальный и минимальный элементы (если таковых несколько – удалить
нужно все). По окончании работы процедуры количество выделенной памяти
должно уменьшиться.
*/


#include "pch.h"
#include <iostream>
using namespace std;



int*  deleteMinMax(int *p_dArray1, int &size)
{
	int z, y;  // индекс для операций с элементами массива
	int elementCount = 0; //  число  элементов 
	int minValue;
	int maxValue;

	/* находим минимальное и максимальное значение в массиве
	 считаем количество  элементов исходного массива, совпадающих с минимальным и максимальным значениями
	 создаем новый массив 
	 копируем все  элементы , отличные от мин и макс в новый массив
	 удаляем старый массив
	 возвращаем указатель на новый массив*/


	maxValue = p_dArray1[0]; //присваиваем макс и мин значениям первый элемент массива
	minValue = p_dArray1[0];

	for (z = 0; z < size; z++) {     //  вывод значений его элементов
		cout << "Value of " << z << " element is " << p_dArray1[z] << endl;

		if (p_dArray1[z] > maxValue) {   // ищем макс
			maxValue = p_dArray1[z]; 
		}; 
		if (p_dArray1[z] < minValue) {    // ищем мин
			minValue = p_dArray1[z]; 
		}; 
	}


	cout << "Max : " << maxValue << endl;
	cout << "Min : " << minValue << endl;

	

	for (z = 0; z < size; z++) {
		if (p_dArray1[z] != minValue && p_dArray1[z] != maxValue) {   // считаем количество  элементов исходного массива, которые остаются
			elementCount++; 
		}; 
	}

	int *p_tempArray = new int[elementCount]; // создаем новый массив 





	y = 0; // обнуляем индекс массива-приемника
	for (z = 0; z < size; z++) {
		if (p_dArray1[z] != minValue && p_dArray1[z] != maxValue) {   // перегоняем в новый массив нужные  элементы
			p_tempArray[y] = p_dArray1[z];
			y++;
		}  
	}


	size = elementCount;  //сохраняем размерность нового массива
	delete[] p_dArray1; // очистка памяти
	return p_tempArray;

}


int main()
{
	int num; // размер массива
	int i; 

	cout << "Enter integer value: ";
	cin >> num; 
	int *p_dArray = new int[num]; // Выделение памяти для массива
	cout << "Enter element value one by one : " << endl;
	for (i = 0; i < num; i++) {
		cin >> p_dArray[i];
	}



	p_dArray = deleteMinMax(p_dArray, num);  





	cout << "New array after delete Max and Min  values : " << endl;
	for (i = 0; i < num; i++) {    //  вывод значений его элементов
		cout << "Value of " << i << " element is " << p_dArray[i] << endl;
	}


	delete[] p_dArray; // очистка памяти
	return 0;
}