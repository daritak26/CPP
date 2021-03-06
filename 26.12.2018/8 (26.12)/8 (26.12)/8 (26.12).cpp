/*
8) Реализуйте решение дискретной задачи о рюкзаке
*/


#include "pch.h"
#include <iostream>
using namespace std;

const int W = 7;           // максимальный вес, который можно положить в рюкзак
const int n = 4;          // количество предметов
int w[n] = { 1,3,4,5 };  // веса предметов
int p[n] = { 1,4,5,7 };  // ценности предметов


int a[n][W + 1];  // двумерный массив для таблицы

int i, k, s;  //индексы
int totalW = 0; // общий вес набранного
int totalSum = 0; // общая сумма набранного

int max(int x, int y)
{
	if (x > y) return x; else return y;
}


void findAns(int k, int s) // функция , находящая набор предметов, входящих в рюкзак
{
	if (a[k][s] == 0)
		return;
	if (a[k - 1][s] == a[k][s]) {
		findAns(k - 1, s); //
	}
	else {
		findAns(k - 1, s - w[k]); //

		// найденный предмет выводим на экран, а также суммируем общий вес и общую стоимость к ранее найденным
		cout << "weight = " << w[k] << " sum = " << p[k] << endl;
		totalW = totalW + w[k]; // общий вес набранного
		totalSum = totalSum + p[k]; // общая сумма набранного
	}
}




int main()
{
	//Первые элементы приравниваем к 0
	for (i = 0; i <= W; i++) {
		a[0][i] = 0;
	}

	for (i = 0; i < n; i++) {
		a[i][0] = 0;
	}


	for (k = 0; k < n; k++) {
		for (s = 1; s <= W; s++) {                                            //Перебираем для каждого k все вместимости 
			if (s >= w[k]) {                                                  //Если текущий предмет вмещается в рюкзак 
				a[k][s] = max(a[k - 1][s], a[k - 1][s - w[k]] + p[k]);       //Выбираем класть его или нет 
			}
			else {
				a[k][s] = a[k - 1][s];               //Иначе, не кладем 
			}
		}
	}


	// Затем найдем набор  предметов, входящих в рюкзак, рекурсивной функцией:
	findAns(n - 1, W);

	cout << "total Weight = " << totalW << " total Sum = " << totalSum << endl;

}


