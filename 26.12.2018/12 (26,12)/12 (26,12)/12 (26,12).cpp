/*  12) На прямой дощечке вбиты гвоздики. Любые два гвоздика можно соединить
ниточкой. Требуется соединить некоторые пары гвоздиков ниточками так, чтобы
к каждому гвоздику была привязана хотя бы одна ниточка, а суммарная длина
всех ниточек была минимальна.
В первой строке записано число N - количество
гвоздиков (2 ≤ N ≤ 100). В следующей строке записано N чисел - координаты
всех гвоздиков (неотрицательные целые числа, не превосходящие 10000).
*/

#include "pch.h"
#include <iostream>
using namespace std;

int min(int x, int y)  // Функция - возвращает минимум двух значений
{
	if (x <= y) return x;
	else return y;

}


void quickSort(int *numbers, int left, int right)   // Сортировка
{
	int pivot; // Разрешающий элемент
	int l_hold = left; //Левая граница
	int r_hold = right; // Правая граница
	pivot = numbers[left];
	while (left < right) // Пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // Сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // Если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // Перемещаем элемент [right] на место разрешающего
			left++; // Сдвигаем левую границу вправо 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // Сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // Если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // Перемещаем элемент [left] на место [right]
			right--; // Сдвигаем правую границу вправо 
		}
	}
	numbers[left] = pivot; // Ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}


int main()
{

	const int maxN = 101; // Максимальное количество гвоздей , 100 + 1
	// Создаем 2 массива размера 100+1 , один для координат гвоздей, второй для длин ниток
	int a[maxN];  
	int dp[maxN]; // Пусть dp[i] равно минимальной суммарной длине всех нитей, когда любые два гвоздя от первого (нумерация гвоздей начинается с 1) до i-го соединены нитью.
			      // то есть в алгоритме идет накопление

	int n; // Количество гвоздей

	cout << "Enter  N = ";
	cin >> n; 

	cout << "Enter " << n << " values = " << endl;
	//int i;
	for (int i = 1; i <= n; i++)  // Читаем с клавиатуры координаты гвоздей. складываем в массив, начиная с 1 элемента.
	{
		cin >> a[i];
	}
	a[0] = 0;   // Неиспользуемый 0 элемент инициализируем нулем. иначе  ошибка.


	quickSort(a, 1, n);  // Сортируем координаты

	dp[0] = 0;    // Нулевой гвоздь не нужен, но инициализировать его надо, иначе вылетит ошибка.
	dp[1] = 0;    // 1 гвоздь невозможно сосединить сам с собой ниткой (точнее - можно, нулевой длины)

	dp[2] = a[2] - a[1];  //При n = 2 оба гвоздя обязательно должны быть соединены нитью. вот ее длина
	dp[3] = a[3] - a[1];  // При n = 3 следует соединить первый гвоздь со вторым, а второй с третьим. вот ее общая длина

	for (int i = 4; i <= n; i++)   // Начиная с 4, по формуле
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + a[i] - a[i - 1];
	}


	cout << "Result = " << dp[n] << endl; // Последний элемент массива dp[] содержит искомую длину.


}


