/*7) Напишите программу переводящую число в систему счисления с основание k,
где k не превышает 30.
*/



#include "pch.h"
#include <iostream>
using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");

	long n, z;
	int k;
	char c;
	char str1[255] = "";
	char str2[255] = "";
	int i = 0;
	int j = 0;

	cout << "Введите число в десятичной системе ";
	cin >> n;
	cout << "Введите k ";
	cin >> k;
	
	while (n >= 1)
	{
		z = n % k;
		if (z < 10) str1[i] = z + 48; // переводим в код символа. цифры 0-9
    	else str1[i] = z + 55;  // буквы - больше 10
    	i++;
     	n = n / k;
     }
     // переворачиваем строку. в результате работы кода выше - старший разряд оказался в самом конце. надо перевернуть.
     for (j = 0; j < i; j++)
     {
     str2[j] = str1[i - j - 1];
     }
cout << str2 << endl;
}