/*
27) Для структуры Warehouse напишите конструктор копий и оператор присваивания.
*/

#include "pch.h"
#include <iostream>

using namespace std;

struct Product {
	const char* name;
	unsigned int price;
	unsigned int weight;
};

struct Warehouse {
	Product* Goods;
	unsigned int size;
	Warehouse(unsigned int size1);
	Warehouse(const Warehouse &other);
	~Warehouse();
};

Warehouse::Warehouse( const Warehouse &other)
{
	unsigned int i;
	size = other.size;

	Goods = new Product[other.size];   // создаем динасический массив обьектов типа Product размером size  для хранения товаров

	for (i=0; i< other.size; i++)
	{
		Goods[i] = other.Goods[i];
		
	}
	
	cout << " COPY constructor Warehouse " << this << endl;
}

Warehouse::Warehouse(unsigned int size1)
{
	size = size1;
	Goods = new Product[size];   // создаем динасический массив обьектов типа Product размером size  для хранения товаров
	cout << " constructor Warehouse " << this << endl;
}

Warehouse::~Warehouse()
{
	delete[]  Goods; // освобождаем память
	size = 0;
	cout << " destructor Warehouse "<< this << endl;
}

int main()
{
	unsigned int i;
	unsigned int numOfGoods = 5;

	
	Warehouse warehouse(numOfGoods);  // создаем СТАТИЧЕСКИЙ  экземпляр структуры типа Warehouse , который будет содержать фиксированное число
											// экземпляров типа Product. продукты у нас создаются автоматически в конструкторе Warehouse при его создании..

	for (i = 0; i < warehouse.size; i++)
	{
		warehouse.Goods[i].name = "Product name";  // в цикле набиваем продукты случайными данными. имя вот только фиксированное. 
		warehouse.Goods[i].price = 10 + i;
		warehouse.Goods[i].weight = 22 + i;

	}

	//выводим на экран

	for (i = 0;i < warehouse.size;i++) {
		cout << "warehouse Product : " << warehouse.Goods[i].name << " ";
		cout << " price : " << warehouse.Goods[i].price << " ";
		cout << " weight : " << warehouse.Goods[i].weight << endl;

	}


	Warehouse warehouse1(warehouse);


	//выводим на экран из второго 

	for (i = 0;i < warehouse1.size;i++) {
		cout << "warehouse1 Product : " << warehouse1.Goods[i].name << " ";
		cout << " price : " << warehouse1.Goods[i].price << " ";
		cout << " weight : " << warehouse1.Goods[i].weight << endl;

	}
	


	return 0;
}