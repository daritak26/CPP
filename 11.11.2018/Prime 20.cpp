
/*
20) Напишите процедуру, удаляющую из динамически выделенной строки лишние
пробелы. Не лишними считаются одиночные пробелы, разделяющие пару слов. По
окончании работы процедуры количество выделенной памяти должно
увеличиться
*/






#include "pch.h"
#include <iostream>
using namespace std;

char*  deleteSpaces(char *dString, int &size)
{
	char lastChar, currentChar;
	int i,z;
	int localCount = 0;

	if (!dString[0]) return dString; // строка пустая ! ее же и возвращаем без обработки


	currentChar = lastChar = dString[0];
	
	for (i = 0; i < size;i++)
	{
		currentChar = dString[i];
		if (!   (lastChar == ' ' && currentChar == ' ')   )  
		{
			localCount++;
		}
		lastChar = currentChar;
	}

	cout << localCount << endl;

	char *tempString = new char[localCount]; // создаем новый массив 


	currentChar = lastChar = dString[0];
	z = 0;
	for (i = 0; i < size;i++)
	{
		currentChar = dString[i];
		
		if (!(lastChar == ' ' && currentChar == ' '))
		{
			tempString[z] = dString[i];
			z++;
		}
		lastChar = currentChar;
	}

	size = z;
	return tempString;
}



int main()
{
	const char someText[] = " some    simple        text     with       spaces       ";  // строка для сжатия
	int i;
	int charCount = 0;

	i = 0;
	while (someText[i++])     charCount++; // считаем ее длину
	charCount++; // и еще один символ.  для нуля в конце строки.

char *dstr = new char[charCount]; // создаем динамическую строку как массив char

for (i = 0; i < charCount; i++) // перегоняем туда символы 
{
	dstr[i] = someText[i];
}


//cout << someText << endl;
cout << dstr << endl;

dstr = deleteSpaces(dstr, charCount); // отдаем функции - обработчику

cout << dstr << endl;

	
delete[] dstr;
	return 0;

}