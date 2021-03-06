/*18) Напишите логическую функцию, проверяющую, является строка палиндромом.
Можно считать, что строка состоит только из букв латиницы.*/


#include "pch.h"
#include <iostream>
using namespace std;


bool isPalindrom(char inputString[255])
{
	int i, j;
	int charCount = 0;
	char tempString[255];

	// Можно считать, что строка состоит только из букв латиницы. - однобайтная кодировка.

	i = 0;
	while (inputString[i++])
	{
		charCount++;
	}   // ищем длину строки. проходим все элементы, пока не дойдем до нуля.
			// строка как мы помним оканчивается нулем



	j = 0;
	for (i = charCount - 1; i >= 0; i--)  // записываем во временную строку символы в обратном порядке начиная с конца
	{
		tempString[j] = inputString[i];
		j++;
	}
	tempString[j] = '\0'; // добавляем в конец ноль - признак конца строки




	for (i = 0; i < charCount + 1; i++) // попозиционное сравнение 
	{
		if (tempString[i] != inputString[i]) {
			cout << "NO" << endl;
			return false;
		}// хоть один не сошелся - дальше можно не проверять
	}
	cout << "YES" << endl;
	return true;  // все позиции прошли сравнение успешно. строки одинаковые
}




int main()

{
	char str1[255] = "ABBA";
	char str2[255] = "ABBAtines";

	//1
	cout << str1 << " isPalindrom = " << isPalindrom(str1) << endl << endl;

	//2 
	cout << str2 << " isPalindrom = " << isPalindrom(str2) << endl;

	return 0;

}
