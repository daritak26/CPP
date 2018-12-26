
/*
1) Напишите программу, находящую k-ую порядковую статистику. Программа
должна работать за время O(n) в среднем.
*/


#include "pch.h"
#include <iostream>
using namespace std;


int main()
{
	const unsigned n = 12; // размер массива
	unsigned a[n] = {8,1,6,3,4,5,2,7,0,9,1,3}; // сам массив
	unsigned k = 8; // номер статистики
	
	unsigned L, R, i, j;
	unsigned w, x;

	for (i = 0; i < n; i++) // выводим исходный массив для отладки
	{
		cout << a[i] << " ";
	}
	cout << endl;



//На первом шаге вызывается процедура разделения с L=1 и R=N (т.е. разделение выполняется для всего массива), причём в качестве разделяющего значения x выбирается a[k].		
	L = 0;        // массивы в с++ индексируются  с нуля..
	R = n - 1;



while (L < R - 1)
{

x = a[k]; // разделитель
i = L;
j = R;
	
for (;;)  //REPEAT
	{
		while (a[i] < x)
		{
		   i = i + 1;
		}

		while (x < a[j])
		{
			j = j - 1;
		}

		if (i <= j)
		{
			w = a[i];    // обмен значений массива 
			a[i] = a[j];
			a[j] = w;

			i = i + 1;
			j = j - 1;
		}
		if (i > j) break;  //UNTIL i > j;

	
	}

	if (j < k) 		L  = i;
	if (k < i) 		R  = j;

}
	

for (i = 0; i < n; i++) //  выводим массив после сортировки
{ 
	cout << a[i]<< " " ; 
}
cout << endl;


cout << "k=" << k << endl;

cout << "a[k]=" << a[k] << endl; // к-й элемент массива - результат

}

