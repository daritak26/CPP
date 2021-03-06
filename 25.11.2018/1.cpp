/* 1. Напишите программу, находящую корни уравнения
2018X + 2019Y = 78487894
эффективным перебором.*/


#include "pch.h"
#include <iostream> 
using namespace std;

int main() {
	int N = 78487894;
	unsigned int X;
	for (unsigned int Y = 1; Y < 38875; Y++) {
		if ((78487894 - (2019 * Y)) % 2018 == 0) {
			X = (N - (2019 * Y)) / 2018;
			cout << "Y = " << Y << " X = " << X << "\n";
		}
	}
	return 0;
}
