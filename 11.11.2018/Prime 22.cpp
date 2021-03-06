/*
22) Для структуры Date напишите метод, определяющий, сколько дней осталось до
Нового Года.
*/


#include "pch.h"
#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
	string getDayOfWeek();
	int getNyReminder();
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


	h = (q + 26 * (m + 1) / 10 + k + k / 4 - 2 * e) % 7;

	switch (h)
	{
	case 1: return("Sunday"); break;
	case 2: return("Monday"); break;
	case 3: return("Tuesday"); break;
	case 4: return("Wednesday"); break;
	case 5: return("Thursday"); break;
	case 6: return("Friday"); break;
	case 7: return("Saturday"); break;
	default: return("ERROR.."); break;
	}


}


int Date::getNyReminder()
{
	int i;
	int numOfDays; // сколько дней в месяце
	int daysTotal=0; // счетчик дней в полных месяцах начиная с первого
	

	for (i = 1; i < month; i++)
	{

		numOfDays=0; 
		switch (i)
		{
		case 1: numOfDays = 31; break;
		case 2: if (year % 4) { 
			numOfDays = 28; 
			break; 
		}
				else { 
			numOfDays = 29; // високосный год
			break; 
		}
		case 3: numOfDays = 31; break;
		case 4: numOfDays = 30; break;
		case 5: numOfDays = 31; break;
		case 6: numOfDays = 30; break;
		case 7: numOfDays = 31; break;
		case 8: numOfDays = 31; break;
		case 9: numOfDays = 30; break;
		case 10: numOfDays = 31; break;
		case 11: numOfDays = 30; break;
		case 12: numOfDays = 31; break;

		default: 	break;
		}
		daysTotal = daysTotal + numOfDays;


	}

	daysTotal = daysTotal + day; // к количеству дней в полных месяцах прибавляем количество дней

	

	if (year % 4) {
		return 365 - daysTotal;
	}
	else {
		return 366 - daysTotal; // високосный год
	}
}






int main()
{
	Date date;

	date.year = 2018;  // задаем дату
	date.month = 12;
	date.day = 1;


	cout << date.getNyReminder()<< endl; // выводим результат 
	


	return 0;

}
