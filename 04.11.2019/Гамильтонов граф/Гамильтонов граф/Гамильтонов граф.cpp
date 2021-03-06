#include "pch.h"
#include <iostream>
using namespace std;

int n; // Количество вершин
int m; // Количество ребер

int* findHamiltonianCycle(int** array1, int* circle)
{
	for (int i = 0; i < n; i++)  // Массив с вершинами
		circle[i] = i;
	
	int start = 0; // Начало
	int end = n;  //  Конец
	for (int k = 0; k <= n * (n - 1); k++)
	{
		if (array1[start][start + 1] == 1)
		{
			end = start;
			start++; 
		}
		else
		{
			int i = 2;
			while (array1[start][i] != 1 && array1[start + 1][i + 1])
				i++;
			for (int j = 0; j < ((i - start - 1) / 2); j++)
			{
				swap(circle[start + 1 + j], circle[i - j]); 
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << circle[i] << " ";
	}

	return circle;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Количество вершин " << endl;
	cin >> n;
	cout << "Количество ребер " << endl;
	cin >> m;
	
	int **matrix = new int*[n]; // Матрица смежности
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	

	int **circle = new int*[n];
	for (int i = 0; i < n; i++)
		circle[i] = new int[n];


	findHamiltonianCycle(matrix, *circle);
	return 0;
}

