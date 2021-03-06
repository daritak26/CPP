/*
26) Для структуры Warehouse напишите конструктор и деструктор.

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
	~Warehouse();
};

Warehouse::Warehouse(unsigned int size1)
{
	size = size1;
	Goods = new Product[size];   // создаем динамический массив обьектов типа Product размером size  для хранения товаров
	//cout << " constructor Warehouse " << endl;
}

Warehouse::~Warehouse()
{
	delete[]  Goods; // освобождаем память
	size = 0; // просто для красоты
	//cout << " destructor Warehouse " << endl;
}

int main()
{
	unsigned int i;
	unsigned int numOfGoods=0;

	cout << "Enter number of goods (int) : " << endl;
	cin >> numOfGoods;


	Warehouse* warehouse;
	 warehouse = new Warehouse(numOfGoods);  // создаем экземпляр структуры типа Warehouse , который будет содержать введенное пользователем число
	                                         // экземпляров типа Product. продукты у нас создаются автоматически в конструкторе Warehouse при его создании..

	 for (i = 0;  i < warehouse->size;   i++) 
	 {
		 warehouse->Goods[i].name = "Product name";  // в цикле набиваем продукты случайными данными. имя вот только фиксированное.
		 warehouse->Goods[i].price = 10+i;
		 warehouse->Goods[i].weight = 22+i;

	 }

	 //выводим на экран

	 for (i = 0;i < numOfGoods;i++) {
		 cout << "Product : "<< warehouse->Goods[i].name << " ";
		 cout << "price : " << warehouse->Goods[i].price << " ";
		 cout << "weight : " << warehouse->Goods[i].weight << endl;
	
	 }

	 delete warehouse;

	return 0; 

}