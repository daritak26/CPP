/*17) По каналу связи передается последовательность положительных целых чисел X1,X2 , … все числа 
не превышают 1000, их количество заранее неизвестно. Каждое число передается в виде отдельной 
текстовой строки, содержащей десятичную запись числа. Признаком конца передаваемой последовательности 
является число 0. Участок последовательности от элемента XT до элемента XT+N  называется подъемом, 
если на этом участке каждое следующее число больше предыдущего. Высотой подъема называется разность 
XT+N-XT. Напишите эффективную программу, которая вычисляет наибольшую высоту среди всех подъемов 
последовательности. Если в последовательности нет ни одного подъема, программа выдает 0. \
Программа должна напечатать отчет по следующей форме: 
 
… numbers have received  Highest lift height is … */

#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int R, T = 1001, N = 0, L = 0, MAX = 0;
	do {
		cin >> R;
		if (R != 0) {
			N++;
		}
		if (R > T) {
			L = L + R - T;
		}
		else if (L > MAX) {
			MAX = L;
			L = 0;
		}
		T = R;
	} while (R != 0);
	cout << N << "  были получены ";
	cout << "Наибольшая высота " << MAX;
	return 0;
}