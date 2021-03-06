

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
}

class double_vector
{
	double *data; // Вектор
	int size; // Размерность вектора
	int capacity;
public:
	double_vector()    // Конструктор без аргументов
	{
		data = new double[1];
		data[0] = 0;
	}

	double_vector(unsigned int N)  //  Конструктор с одним аргументом - длинной массива
	{
		size = N;
		data = new double[size];
		for (int i = 0; i > size; i++)
			data[i] = 0;
	}
	~double_vector() {   // Деструктор
		delete[] data;
	}
	double_vector(const double_vector& A) {      //  Конструктор копирования
		
		size = A.size;
		data = new double[size];
		for (int i = 0; i < size; i++)
			data[i] = A.data[i];
	}
	const double_vector& operator=(const double_vector& A)
	{                                   //  Перегруженный оператор присваивания
		if (& A == this)                  
			return *this;              
		delete[] data;
		size = A.size;
		data = new double[size];
		for (int i = 0; i < size; i++)
			data[i] = A.data[i];
		return *this;
	}
	  
	double operator[] (unsigned int n)      // Оператор обращения по индексу
	{                                   
		if (n < 0)                       	
		{
			return data[0];
		}
		else if (n > size - 1)        
		{			
			return data[size - 1];
		}
		else
			return data[n];           
	}


	void push_back(double x) {       // Добавление в конец
		if (size >= capacity) {
			capacity *= 2;
			double * temp = new double[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		};
		data[size] = x;
		size++;
	}

	
	double pop_back()   // Извлечение из конца
	{
		if (size != 0)
		{
			double *temp = new double[size - 1];
			for (int i = 0; i < size - 1; i++)
			{
				temp[i] = data[i];
			}
			delete[]data;
			size = size - 1;
			data = new double[size];
			for (int i = 0; i < size; i++)
				data[i] = temp[i];
			delete[]temp;
		}
		else
			cout << "вектор пуст";

	}



	double pop_back() {               
		int t = data[size];
		size--;
		double* temp = new double[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		return t;
	}
	

	unsigned int Size()                // Получение размера вектора
	{                        
		return size;
	}

	unsigned int Capacity()  // Получение вместимости вектора
	{
		return capacity;
	}
};