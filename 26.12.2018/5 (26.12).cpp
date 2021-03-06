//5) Реализуйте решение непрерывной задачи о рюкзаке


#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Количество товаров " << endl;
	cin >> N;

	int *arrayM = new int[N];    // массив с количеством каждого товара
	for (int i = 0; i < N; i++) {
		cout << "Количество товара № " << i << " ";
		cin >> arrayM[i];
	}

	cout << endl;

	int *arrayC = new int[N];     // массив с ценами за каждый товар
	for (int i = 0; i < N; i++) {
		cout << "Цена товара № " << i << " ";
		cin >> arrayC[i];
	}

	cout << endl;

	double *arrayU = new double[N];      // массив с ценами за ед товара
	for (int i = 0; i < N; i++) {
		arrayU[i] = double((double)arrayC[i] / (double)arrayM[i]);
		cout << "Цена за единицу товара № " << i << " = " << arrayU[i] << endl;
	}



	int i, j;
	double** matrix;


	matrix = new double*[N];       // двумерный массив с ценами за ед и кол-вом товара
	for (i = 0; i < N; i++)
		matrix[i] = new double[2];

	for (i = 0; i < N; i++)  
		for (j = 0; j < 2; j++)
		{
			if (j == 0) {
				matrix[i][j] = arrayM[i];   // столбец с ценой за ед товара
			}
			else {
				matrix[i][j] = arrayU[i];    // столбец с кол-вом товара
			}
		}



	cout << endl;


	for (i = 0; i < N; i++) {
		for (j = 0; j < 2; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < N; i++)   //сортируем двумерный массив по убыванию цен за ед
	{
		int max = i;

		for (int j = i + 1; j < N; j++)
		{
			if (matrix[j][1] > matrix[max][1])
			{
				max = j;
			}
		}

		if (max != i)
		{
			int tmp[2] = { matrix[i][0],  matrix[i][1] };
			matrix[i][0] = matrix[max][0];  matrix[i][1] = matrix[max][1];
			matrix[max][0] = tmp[0];  matrix[max][1] = tmp[1];
		}
	}

	cout << endl << endl;


	for (i = 0; i < N; i++) {    //выводим отсортированный массив
		for (j = 0; j < 2; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	int W;
	cout << "Вместимость рюкзака " << endl;
	cin >> W;
	int Sum = 0;
	int k = 0;
	int p = 1;


	for (int i = 0; i < N; i++)  // отсортированные данные записываем обратно в одномерные массивы
	{
		arrayM[i] = matrix[i][k];
		cout << arrayM[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		arrayU[i] = matrix[i][p];
		cout << arrayU[i] << " ";
	}

	for (int i = 0; i < N; i++) {

		
			if (arrayM[i] < W)
			{
				Sum = Sum + arrayM[i] * arrayU[i];
				W = W - arrayM[i];
			}
			else {
				if (W > 0) {
					Sum = Sum + W * arrayU[i];
					W = 0;
				}
			}
		
	}
	cout << endl;

	cout << "Стоимость товаров в рюкзаке  " << Sum;
	delete[] arrayM;
	delete[] arrayC;
	delete[] arrayU;
	delete[] matrix;
	return 0;
}

