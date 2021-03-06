/* 6) Реализуйте метод секущих вычисления корня уравнения */

#include "pch.h"
#include <iostream>
using namespace std;

double f(double x)
{
	return 3 * x*x*x - 12 * x*x + 10 * x - 100;  // вот такая у нас функция будет..  ищем корень уравнения 3х3 - 12х2 + 10х -100 = 0
}

int main()

{                         // входные данные
	double x0 = -100.0;   // начальное приближение. нижнее значение
	double x1 = 100.0;    // начальное приближение. верхнее  значение
	double e = 0.000001;  // точность
	const int maxIteration = 2000000;  // максимальное количество итераций. если алгоритм не сойдется, не попасть в бесконечный цикл.
	double rez;
	double f0, f1;
	rez = x1;
	int i = 0;
	do {
		f1 = f(rez);
		f0 = f(x0);
		rez = rez - f1 / (f1 - f0)*(rez - x0);
		i++;
	} while (fabs(f1) > e && i < maxIteration);  // fabs - модуль числа . выходим либо когда достигнута заданная точность решения, либо по максимальному количеству итераций.
	cout << "Number of iterations = " << i << endl;
	cout << "Result = " << rez << endl;
}