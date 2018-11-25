// 6. Напишите программу, находящую все простые числа Ченя не превосходящие n. 

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool abc(int n)
{
	int i = 2, k;
	k = sqrt(n);
	while (((n % i) != 0) && (i <= k))
	{
		i++;

	}
	return i > k;
}
int main()
{
	int i, k, n, m = 0;
	cout << "k = ";
	cin >> k;
	cout << "n = ";
	cin >> n;

	for (i = k; i < n; i++)
	{
		if (abc(i) && abc(i * 2 + 1))
		{
			cout << i << " ";
			m = 1;
		}
	}
	if (m == 0)
		cout << m;

	return 0;
}