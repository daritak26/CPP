/* 4. Напишите программу находящую первые n составных чисел.
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int number, amount, l = 0; // l - счетчик количества составных чисел
	cout << "n = ";
	cin >> amount; // вводим количество составных чисеел
	cout << "Composite: ";
	for (number = 4; l < amount; number++) {  // перебираем все числа, начиная с первого составного, пока счетчик не станет равным введенному числу
		for (int i = 2; i < number; i++) {    // проверям число на простоту
			if ((number % i) == 0) {    // если составное, то выводим на экран и увеличиваем счетчик на 1
				cout << number << ' ';
				l++;
				break;
			}
		}
	}
	return 0;

}