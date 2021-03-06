/* 3) Напишите программу позволяющую эффективно проверять принадлежность пары значений массиву.
Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет. Можно считать,
что количество запросов многократно превышает размер массива*/


#include "pch.h"
#include <iostream>
using namespace std;

int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значения в ячейке
			left = midd + 1;       // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");

	int SIZE;

	cout << "Количество элементов в массиве ";
	cin >> SIZE;

	int *array = new int[SIZE];
	int key = 0;
	int key2 = 0;
	int index = 0;
	int index2 = 0;


	cout << endl << "Введите элементы массива в порядке возрастания  ";
	for (int i = 0; i < SIZE; i++) // заполняем массив
	{
		cin >> array[i];
	}

	cout << endl << "Введите пару чисел в порядке возрастания: ";
	cin >> key >> key2;

	index = Search_Binary(array, 0, SIZE, key);

	if (index >= 0) {
		
			index2 = Search_Binary(array, index, SIZE, key2);
		if (index2 >= 0)
			cout << "Пара чисел принадлежит массиву" << endl;
		else
			cout << "Пара чисел не принадлежит массиву" << endl;
	}
	else
		cout << "Пара чисел не принадлежит массиву" << endl;

	return 0;
}