/*Реализуйте структуру данных циклический массив пар целых чисел.Циклический массив размера N - массив в котором за последним элементом(N-1) снова 
идет первый(0) и так далее. В этой задаче необходимо использовать структуру pair из STL( http://www.cplusplus.com/reference/utility/pair/pair/ ).
15 баллов
Стандартные для массива (array) поля и методы. 
15 баллов
Сдвиг всех элементов массива на k позиций влево по циклу, работающий за O(1). 
k - целое число.
Пример сдвига на 3 позиции влево
(1,2,3,4,5,6,7,8,9) -> (4,5,6,7,8,9,1,2,3)
Комментарий: в задаче должны быть реализованы стандартные поля и методы, но никто не запрещает добавлять другие или как-то преобразовывать данные.

*/

#include "pch.h"
#include <iostream>
#include <utility>

using namespace std;

class ABC
{
public:
	pair <int, int>* data;
	int I = 0;
	int arraySize;

	ABC(int N)
	{
		arraySize = N;
		data = new pair <int, int>[N];
	};

	ABC(ABC& A)
	{
		arraySize = A.arraySize;
		data = A.data;
	};

	~ABC()
	{
		delete[] data;
	};

	pair <int, int> &operator[](int i)
	{
		while (i >= arraySize)
		{
			i -= arraySize;
		}
		return data[i];
	};

	void input()
	{
		int j, a, b;
		for (int i = I; i < arraySize + I; i++)
		{
			j = i;
			while (j >= arraySize)
				j -= arraySize;
			cin >> a >> b;
			data[j] = make_pair(a, b);
		}
	};

	void output()
	{
		int j;
		for (int i = I; i < arraySize + I; i++)
		{
			j = i;
			while (j >= arraySize)
				j -= arraySize;
			cout << data[j].first << " " << data[j].second << endl;
		}
	};

	void Move(int k)
	{
		I += k;
	}
};