/*Напишите переборную программу, находящую для заданной последовательности
длины N целых чисел необходимо: максимальное произведение двух её
элементов, номера которых различаются не менее чем на 5. Программа может
быть неэффективной*/

#include "pch.h"
#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b) {
		return a;
	}
	return b;
}
int maxMult(int *array, int arraySize) {
	int result = 0;
	for (int i = 0; i < arraySize - 5; i++) {
		for (int j = i + 5; j < arraySize; j++) {
			result = max(result, array[i] * array[j]);
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
	cout << maxMult(array, N);
	return 0;
}