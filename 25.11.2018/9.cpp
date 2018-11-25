 /* 9. Напишите программу, находящую все простые числа Ченя не превосходящие n.*/
#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool abc(int n)
{
	int i = 3, max, k = 0;
	bool p;


	max = sqrt(n);
	p = n != 1;
	if ((n > 2) && (n % 2 == 0))
		p = false;
	else
		while (i <= max)
		{
			if (n % i == 0)
			{
				p = false;
				break;
			}

			i = i + 2;
		}
	return p;
}
int main()
{
	int n, i;

	cout << "n = ";
	cin >> n;
	for (i = 1; i < n; i++)
	{
		if (abc(i))
			cout << i << ' ';
	}
}