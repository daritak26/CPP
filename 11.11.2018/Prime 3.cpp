// 3) Напишите программу, вычисляющую биномиальный коэффициент из n по к. В программе нельзя использовать числа, превышающие итоговое значение. 

#include "pch.h"
#include <iostream>
using namespace std;

long long fakt(int n)    // функция для нахождения факториала
{
	int r;
	long long fact=1;
	for (r = 1; r<=n; r++)
		fact=fact*r;
	return fact;
}


unsigned bci(int n, int k)    //  функция для расчета C(n,k)
{
	int b;
	b = n - k;

	return fakt(n) / (fakt(k)*fakt(b));
}

int main()
{
	unsigned m;
	int n, k;
	

	
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;

	

	m = bci(n, k);
	cout << "binom: " << m;
	

	return 0;
}

