

#include "pch.h"
#include <iostream>
using namespace std;


class double_vector {
	double * data;
	int size;
	int capacity;
public:

	double_vector(double* A, int n) {      // Конструктор создающий вектор по double-массиву и его размеру
		int* data = new int[n];
		size = n;
		capacity = size * 2;
		for (int i = 0; i < size; i++) {
			data[i] = A[i];
		}
	}

	void resize() {        //  Изменение вместимости массива
		size *= 2;
		capacity = size * 2;
	}

	void push_front(int x) {   // Добавление в начало
		data[0] = x;
		size++;
	}

	int pop_front() {    // Удаление из начала
		int t = data[0];
		size--;
		double * temp = new double[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = data[i + 1];
		delete[] data;
		data = temp;
		return t;
	}

	void insert(int x, int n) {      // Добавление на заданную позицию
		double* temp = new double[capacity];
		size++;
		for (int i = 0; i < size; i++) {
			if (i < n)
				temp[i] = data[i];
			else if (i == n)
				temp[i] = x;
			else
				temp[i] = data[i - 1];
		}
		delete[] data;
		data = temp;
	}

	void erase(int pos) {      // Удаление из заданной позиции
		double* temp = new double[capacity - 1];
		size--;
		for (int i = 0; i < size; i++) {
			if (i < pos)
				temp[i] = data[i];
			else if (i > pos)
				temp[i - 1] = data[i];
		}
		delete[] data;
		data = temp;
	}

	void erase(int a, int b) {       // Удаление интервала по индексам концов отрезка
		double* temp = new double[capacity];
		int diff = b - a - 1;
		size = size - diff;
		for (int i = 0; i < size; i++) {
			if (i < a)
				temp[i] = data[i];
			else if (i > b)
				temp[i - diff] = data[i];
		}
		delete[] data;
		data = temp;
	}

	const double_vector& operator+(const double_vector& A) {      // Конкатенация(слияние) векторов
		double* temp = new double[capacity];
		for (int i = 0; i < size * 2; i++) {
			if (i <= size)
				temp[i] = data[i];
			else
				temp[i] = A[i];
		}
		delete[] data;
		data = temp;
	}

	int find(int x) {                 // Линейный поиск по массиву
		for (int i = 0; i < size; i++)
			if (data[i] == x)
				return i;
	}
};

