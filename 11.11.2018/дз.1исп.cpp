
//  Напишите программу, вычисляющую сумму нечетных цифр целого числа. 

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, a, x;
	cout << "N = ";
	cin >> n;
	while (n != 0)
	{
		x = n % 10;
		a = n % 10 % 2;

			
		if (a != 0)

		{
			sum = sum + x;
			
		}
		n /= 10;

	}
	cout << "sum = " << sum;

	return 0;
}


