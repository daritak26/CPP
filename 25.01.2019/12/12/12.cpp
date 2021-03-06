/*Напишите переборную программу, находящую для заданной последовательности
длины N неотрицательных целых чисел необходимо: минимальную сумму двух её
элементов, номера которых различаются не менее чем на 5. Программа может
быть неэффективной.*/

#include "pch.h"
#include <iostream>

using namespace std;
int min(int a, int b)
{
	if (a < b) {
		return a;
	}
	return b;
}
int minSum(int *array, int arraySize) {
	int result = 2147483647;
	for (int i = 0; i < arraySize - 5; i++) {
		for (int j = i + 5; j < arraySize; j++) {
			result = min(result, array[i] + array[j]);
		}
	}
	return result;
}
int main() {
	int N;
	cin >> N;
	int *array = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	};
	cout << minSum(array, N);
	return 0;
}