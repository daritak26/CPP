/*
12) Напишите процедуру, дописывающую к каждому элементу динамически
выделенного массива справа его квадрат.({1,2,3,4}->{1,1,2,4,3,9,4,16}). По
окончании работы процедуры количество выделенной памяти должно
увеличиться.
*/


#include "pch.h"
#include <iostream>
using namespace std;



int*  addSquare(int *p_dArray1, int &size)
{
	int z, y;  // индекс для операций с элементами массива
	int elementCount = 0; //  число  элементов 
	

	
	/*создаем новый массив с количеством элементов в 2 раза большим исходного
	 копируем все  элементы , к каждому сразу дописываем квадрат
	 удаляем старый массив
	 возвращаем указатель на новый массив */


	

	for (z = 0; z < size; z++) {
		//  вывод значений его элементов
		cout << "Value of " << z << " element is " << p_dArray1[z] << endl;

		
	}

	elementCount = size * 2; //новый массив с количеством элементов в 2 раза большим исходного

	int *p_tempArray = new int[elementCount]; // создаем новый массив 





	y = 0; // обнуляем индекс массива-приемника
	for (z = 0; z < size; z++) {
		
			p_tempArray[y] = p_dArray1[z]; // перегоняем в новый массив нужные  элементы
			y++;
		  
			p_tempArray[y] = p_dArray1[z] * p_dArray1[z]; // добавляем рядом квадрат
			y++;
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
		//  вввод значений  элементов c клавиатуры
		cin >> p_dArray[i];
	}



	p_dArray = addSquare(p_dArray, num);  





	cout << "New array after adding Square values : " << endl;
	for (i = 0; i < num; i++) {
		//  вывод значений его элементов
		cout << "Value of " << i << " element is " << p_dArray[i] << endl;

	}


	delete[] p_dArray; // очистка памяти
	return 0;
}