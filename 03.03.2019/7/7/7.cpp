/*Реализуйте класс int_stack_with_max - стек умеющий за O(1) выдавать максимальный хранимый элемент.
*/

#include "pch.h"
#include <bits.h> 
#include <iostream>
#include<stack>

using namespace std;

class stack_with_max {
	stack <int> abc;
	int MAX;
public:

	void getMAX()
	{
		if (abc.empty())
			cout << "Стек пуст" << endl;
		else
			cout << "Максимальный элмент в стеке: " << MAX << endl;
	}

	void pop() {
		if (abc.empty()) {
			cout << "Стек пуст" << endl;
			return;
		}
		int t = abc.top();
		abc.pop();
		if (t > MAX) {
			cout << MAX << endl;
			MAX = 2 * MAX - t;
		}
		else
			cout << t << endl;
	}

	void push(int x) {
		if (abc.empty()) {
			MAX = x;
			abc.push(x);
			cout << x << endl;
			return;
		}
		if (x > MAX) {
			abc.push(2 * x - MAX);
			MAX = x;
		}
		else
			abc.push(x);
		cout << x << endl;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	return 0;
}