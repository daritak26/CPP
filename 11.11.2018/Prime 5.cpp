//5) Напишите программу, заменяющую составные числа на их самые большие простые делители. 


#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int element;
	bool isDivided = false;

	cout << "Enter integer value " << endl;
	cin >> element;

	

	int m = 0;

	for (int b = 2; b < element; b++) {  // перебором проверяем все числа на делимость

		if (element % b == 0) {

			

			for (int b1 = 2; b1 < b; b1++) { // найденные делители проверяем на НЕделимость

				if (b % b1 == 0) {
					isDivided = true;
					break; // хоть один делитель есть - дальше проверять не нужно. запоминаем результат
				}
				
			}

			if (!isDivided) {
				if (b > m) // отбираем самый большой  из простых делителей
					m = b;
			}
			
		}
	}


	cout << "Result : " << m << endl;
	return 0;
}
