// 10.Напишите функцию вычисляющую праймориал числа.

#include "pch.h"
#include <iostream> 

using namespace std;

int prime(bool *a, int b)
{
	int t = 1;
	bool *arr = new bool[b + 1];
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= b; i++)
	{
		arr[i] = 1;
		for (int i = 2; i <= b; i++)
		{
			if (arr[i])
			{
				for (int j = i + i; j <= b; j += i)
				{
					arr[j] = 0;
				};
			};
		};
		if (arr[i] == 1)
		{
			t *= i;
		};
	};

	return t;
}
int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	bool *array = new bool[n + 1];
	cout << "Result = ";
	cout << prime(array, n);
	return 0;
}