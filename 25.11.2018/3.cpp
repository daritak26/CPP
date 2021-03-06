/*
3. Напишите переборную программу программу, вычисляющую значение функции Эйлера для числа n.
*/

#include "pch.h"
#include <iostream>

using namespace std;

int k(int n) {
	int result = n;
	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


int main() {

	int number, result;
	cout << "Number ";
	cin >> number;
	result = k (number);
	cout << "Result " << result;

	return 0;
}
