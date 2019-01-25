/*24) Дан набор из N целых положительных чисел. Из этих чисел формируются все возможные пары 
(парой считаются два элемента, которые находятся на разных местах в наборе, порядок чисел в паре не учитывается), 
в каждой паре вычисляется сумма элементов. Необходимо определить количество пар, для которых полученная сумма делится на 9. 
Напишите эффективную по времени и по памяти программу для решения этой задачи. */

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, s = 0;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if ((A[i] + A[j]) % 9 == 0)
				s++;
	cout << s;
	return 0;
}
