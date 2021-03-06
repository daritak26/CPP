/*
10) Напишите процедуру, удаляющую из динамически выделенного массива все
четные значения (функция принимает в качестве аргументов – указатель на
массив и его размер). По окончании работы процедуры количество выделенной
памяти должно уменьшиться.
*/


#include "pch.h"
#include <iostream>
using namespace std;



int*  deleteEven(int *p_dArray1, int &size)
{
	int z,y;  
	int oddCount=0; //  число нечетных элементов

	/* считаем количество нечетных элементов исходного массива
	создаем новый массив 
	копируем все нечетные элементы в новый массив
	удаляем старый массив
	возвращаем указатель на новый массив*/

	for (z = 0; z < size; z++) {
		
		cout << "Value of " << z << " element is " << p_dArray1[z] << endl;

		if (p_dArray1[z] % 2 != 0) { oddCount++; }; // считаем количество нечетных элементов исходного массива
		}

	int *p_tempArray = new int[oddCount]; // создаем новый массив 


	y = 0; // обнуляем индекс массива-приемника
	for (z = 0; z < size; z++) {
		if (p_dArray1[z] % 2 != 0) {
			p_tempArray[y] = p_dArray1[z];
			y++;
		}  // перегоняем в новый массив нечетные элементы
	}

	
	size = oddCount;  //сохраняем размерность нового массива
	delete[] p_dArray1; // очистка памяти
	return p_tempArray;
	
}


int main()
{
	int num; 
	int i; 

	cout << "Enter integer value: ";
	cin >> num; // получение от пользователя размера массива
	int *p_dArray = new int[num]; // Выделение памяти для массива
	cout << "Enter element value one by one : " << endl;
	for ( i = 0; i < num; i++) {
		
		cin >> p_dArray[i] ;
		}

	   	 
	
	p_dArray = deleteEven(p_dArray, num);  




	
	cout << "New array after delete Even values : " << endl;
	for (i = 0; i < num; i++) {      //  вывод значений его элементов
		cout << "Value of " << i << " element is " << p_dArray[i] << endl;

	}
	

	delete[] p_dArray; // очистка памяти
	return 0;
}