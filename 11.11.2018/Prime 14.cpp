/*14) Напишите процедуру, проводящую “разжатие” символьного динамически
выделенного массива, сделанное в прошлой задаче. Например строка “3a1b5c2d “
должна перейти в “aaabcccccdd”. Можно считать, что не бывает более девяти
одинаковых букв, идущих подряд.*/




#include "pch.h"
#include <iostream>
using namespace std;

char int2char(int k)
{  /*  возвращает символ по его порядковому номеру в строке. 
	 работает для значений входного параметра k в диапазоне от 0 до 9
	*/

	char arrChar[10] = { '0','1','2','3','4','5','6','7','8','9' };
	return arrChar[k];
}



char*  compress(char *p_dArray1, int &size)
{
	int z, y;  // индекс для операций с элементами массива
	int elementCount = 0; //  число  элементов 
	int localCount = 0; //  число  одинаковых элементов
	char  lastValue;
	char currentValue;


	/* считаем количество  элементов исходного массива, не совпадающих с предыдущим элементом
	 создаем новый массив , размерность= количество из предыдущего пункта*2 - под цифру и букву
	 копируем все  элементы неповторяющиеся  в новый массив и сразу добавляем перед ним цифру
	 удаляем старый массив
	 возвращаем указатель на новый массив
	*/



	for (z = 0; z < size; z++) {     //  вывод значений его элементов
		cout << p_dArray1[z];

		// считаем количество неповторяющихся элементов
		if (z == 0) {               // первый элемент берем как есть без проверки
			currentValue = p_dArray1[z];
			elementCount++;
		}
		else {                // второй и последующие - только если не совпадает с предыдущим элементом
			lastValue = currentValue;
			currentValue = p_dArray1[z];
			if (currentValue != lastValue) { elementCount++; }
		}

	}


	elementCount = elementCount * 2; // когда подсчитали количество неповторяющихся элементов, умножаем его на 2 
	//для каждого элемента нужно хранить счетчик повторений и сам элемент

	char *p_tempArray = new char[elementCount]; // создаем новый массив 





	y = 0; // обнуляем индекс массива-приемника
	for (z = 0; z < size; z++) {      // перегоняем в новый массив   элементы

		if (z == 0) {       // первый элемент берем как есть без проверки
			currentValue = p_dArray1[z];
			localCount = 1;
			lastValue = currentValue;
		}
		else {          // второй и последующие - только если не совпадает с предыдущим элементом
			 
			currentValue = p_dArray1[z];          // берем следующий элемент
			if (currentValue != lastValue) {      // следующий элемент отличен от предыдущего
				p_tempArray[y] = int2char(localCount);       // приводим тип счетчика к char	и помещаем в массив	
				y++;
				p_tempArray[y] = lastValue;        // помещаем в массив сам символ
				y++;

				localCount = 1;        // сбрасываем счетчик
				lastValue = currentValue;     // сохраняем текущее значение для следующей итерации
			}
			else { localCount++; }      // следующий элемент совпадает с  предыдущим - ничего не делаем, только увеличиваем счетчик
		}

	}

	// посде окончания цикла - сохраняем последний найденный элемент и счетчик к нему
	p_tempArray[y] = int2char(localCount);        // приводим тип счетчика к char	и помещаем в массив	
	y++;
	p_tempArray[y] = lastValue; // помещаем в массив сам символ
	y++;


	// с массивом закончили

	size = elementCount;  //сохраняем размерность нового массива
	delete[] p_dArray1; // очистка памяти
	return p_tempArray;

}




char*  decompress(char *p_dArray1, int &size)
{
	int z, y,x ;  // индекс для операций с элементами массива
	int elementCount = 0; //  число  элементов 

	
	for (z = 0; z < size; z=z+2) // подсчитываем сумму числовых элементов массива. это и будет размерность нового массива.
	{
		elementCount = elementCount+ p_dArray1[z] - 48; // перевод char в int
	}


	char *p_tempArray = new char[elementCount]; // создаем новый массив 


	//далее идем в цикле и вставляем в новый массив каждый символ столько раз, сколько величина счетчика перед ним
	y = 0;
	for (z = 0; z < size; z=z+2) //
	{
		for (x = 0; x < p_dArray1[z] - 48; x++) //перевод char в int
		{
			p_tempArray[y] = p_dArray1[z+1];
			y++;
		}
	}

	size = elementCount;  //сохраняем размерность нового массива
	delete[] p_dArray1; // очистка памяти
	return p_tempArray;
}


// вводим данные в виде "aabbbc". Программа сначала сжимает (2a3b1c), а затем обратно разжимает (aabbbc)

int main()
{
	int num; // размер массива
	int i; 

	cout << "Enter integer value: ";
	cin >> num;        
	char *p_dArray = new char[num];    // Выделение памяти для массива
	cout << "Enter element value one by one : " << endl;
	for (i = 0; i < num; i++) {
		cin >> p_dArray[i];
	}



	p_dArray = compress(p_dArray, num);  
cout << "   Compressed array  : ";
	for (i = 0; i < num; i++) {
		//  вывод значений его элементов
		cout << p_dArray[i];

	}

	p_dArray = decompress(p_dArray, num);  //
	   	  
	cout << "   Decompressed array  : "<< endl;
	for (i = 0; i < num; i++) {
		//  вывод значений его элементов
		cout << p_dArray[i];

	}


	//delete[] p_dArray; // очистка памяти
	return 0;
}   