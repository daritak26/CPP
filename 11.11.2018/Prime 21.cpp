/*
21) Для структуры Date напишите метод, выписывающий наименование дня недели по
дате.
*/


/*

Zeller's formula is a formula invented by the German clergyman Christian Zeller (1824–1899) for figuring out the day of the week of a given date, 
without the need of tables. Let

J be the century-number,
K the remaining part of the year-number,
e the residue, which remains when J is divided by 4,
m the number of the month,
q the day of the month,
h the number of the day of the week.

Then h is the remainder that results when

	h = q + 26(m + 1)/10 + K + K/4 - 2e    is divided by 7. 

For the formula to work, January and February have to be taken as months 13 and 14 of the preceding year.
For example, Frederick the Great was born on Jan. 24, 1712, so J = 17, e = 1, K = 11, m = 13, and q = 24. 
Plugging these values into the formula, we get


	24 + 26(13 + 1)/10 + 11 + 11/4 - 2 × 1 = 71 = 70 × 1 + 1.
*/

#include "pch.h"
#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
	string getDayOfWeek();
};


string Date::getDayOfWeek()
{
	int j;// be the century - number,
	int k;// the remaining part of the year - number,
	int	e;//the residue, which remains when J is divided by 4,
	int	m;//the number of the month,
	int	q; //the day of the month,
	int	h;//the number of the day of the week.

	j = year / 100;
	e = j % 4;
	q = day;

	if (month < 3)  //For the formula to work, January and February have to be taken as months 13 and 14 of the preceding year.
	{
		--year;
		m = month + 12;
	}
	else m = month;
	k = year % 100;


		h = (q + 26*(m + 1) / 10 + k + k / 4 - 2*e) % 7;

		switch (h)
		{
		case 1: return("Sunday"); break;
		case 2: return("Monday"); break;
		case 3: return("Tuesday"); break;
		case 4: return("Wednesday"); break;
		case 5: return("Thursday"); break;
		case 6: return("Friday"); break;
		case 7: return("Saturday"); break;
		default : return("ERROR.."); break;
}
	
	
}




int main()
{
	Date date;
	date.year = 2018;
	date.month = 1;
	date.day = 2;
	

	printf("%s", date.getDayOfWeek().c_str());  
	//char и const char ну никак не хотят вместе работать..
	// нашла printf("%s", Переменная_строкового типа.c_str()) - вот так.


	return 0;

}
