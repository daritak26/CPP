
//2) Напишите программу, вычисляющую произведение цифр целого числа, чётность которых совпадает с чётностью последней цифры. 

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, kc = 0, a, posl, proiz = 1, x, k, k1;
	cout << "N = ";
	cin >> n;
	posl = n % 10;
	if (posl % 2 == 0)
		k = 1;
	else k = 0;

	while (n != 0)
	{
		x = n % 10;
		if (n % 10 % 2 == 0)
			k1 = 1;
		else
		{
			k1 = 0;
		}
		if (k1 == k)
		{
			proiz *= x;
		}
		n /= 10;
	}
	cout << proiz;
	return 0;
}

