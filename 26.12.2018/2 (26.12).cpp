/*
2) Напишите функцию находящую корень монотонной вещественной функции f
бинарным поиском. Можно считать что корень обязательно существует. Корнем
будем считать значение x, такое что f(x)<10^(-6)
*/

#include "pch.h"
#include <iostream>
using namespace std;

long double f(long double x)
{
	return 8 * x*x*x + 15 * x - 22;   // выбираем сумму функций третьей и первой степени. они монотонно возрастающие. 
									// значит и вся функция монотонно возрастающая
}




int main()
{

	const double long delta = 1e-6; // заданная точность поиска 


	 long double left = -1e6; // левая граница поиска
	 long double right = 1e6; // правая граница поиска. алгоритм сойдется, если искомое значение лежит внутри диапазона .
	 long double middle;
	 
	
	while (fabs(right - left) > delta)
	{
		middle = (left + right) / 2.0;
		if (f(middle) < 0)
			left = middle;
		else
			right = middle;
	}

	cout << "x = " << left<< endl; 


    
}


