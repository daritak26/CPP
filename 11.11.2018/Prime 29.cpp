/*
29) Для структуры Warehouse напишите методы, возвращающие удельную стоимость самого тяжелого товара и цену товара с наибольшей удельной стоимостью, соответственно.
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
	unsigned int getSumAll();
	unsigned int getMaxPrice();
	unsigned int getMaxWeightSum();
	double getUnitSum(unsigned int getMaxWeightSum(), unsigned int getSumAll());
	unsigned int getSum(unsigned int price, unsigned int weight);
	double getUnitSumMaxWeight(unsigned int getMaxWeightSum(), unsigned int getSumAll())
};

Warehouse::Warehouse(unsigned int size1)
{
	size = size1;
	Goods = new Product[size];   // создаем динасический массив обьектов типа Product размером size  для хранения товаров
	//cout << " constructor Warehouse " << endl;
}

Warehouse::~Warehouse()
{
	delete[]  Goods; // освобождаем память
	size = 0;
	//cout << " destructor Warehouse " << endl;
}

unsigned int Warehouse::getSumAll()
{
	unsigned int i;
	unsigned int sum = 0; // переменная для хранения сумму нарастающим итогом

	for (i = 0; i < size; i++)
	{
		sum = sum + (Goods[i].price*Goods[i].weight); // проходим все подряд, перемножаем и складываем

	}

	return sum;

}

unsigned int Warehouse::getMaxPrice() {
	unsigned int i;
	unsigned int maxPrice = 0; // переменная для хранения сумму нарастающим итогом

	for (i = 0; i < size; i++)
	{
		if (maxPrice < Goods[i].price*Goods[i].weight)
			maxPrice = Goods[i].price*Goods[i].weight;
	}

	return maxPrice;
}

unsigned int Warehouse::getMaxWeightSum() {
	unsigned int i;
	unsigned int maxWeight = 0, maxWeightPrice = 0, maxWeightSum = 0;

	for (i = 0; i < size; i++)
	{
		if (maxWeight < Goods[i].weight) {
			maxWeight = Goods[i].weight;
			maxWeightPrice = Goods[i].price;
		}
		maxWeightSum = maxWeight * maxWeightPrice;
	}

	return maxWeightSum;
}

unsigned int Warehouse::getSum(unsigned int price, unsigned int weight) {

	unsigned int sum = 0;
	sum = price * weight;
	return sum;
}
double Warehouse::getUnitSumMaxWeight(unsigned int getMaxWeightSum(), unsigned int getSumAll()) {
	double unitSumMaxWeight = 0;
	unitSumMaxWeight = getMaxWeightSum() / getSumAll();
	return unitSumMaxWeight;
}

double Warehouse::getUnitSum(unsigned int getSum(), unsigned int getSumAll()) {
	double unitSum = 0;
	unitSum = getSum() / getSumAll();
	return unitSum;
}


int main()
{
	unsigned int i;
	unsigned int numOfGoods = 0;

	cout << "Enter number of goods (int) : " << endl;
	cin >> numOfGoods;


	Warehouse* warehouse;
	warehouse = new Warehouse(numOfGoods);  // создаем экземпляр структуры типа Warehouse , который будет содержать введенное пользователем число
											// экземпляров типа Product. продукты у нас создаются автоматически в конструкторе Warehouse при его создании..

	for (i = 0; i < warehouse->size; i++)
	{
		warehouse->Goods[i].name = "Product name";  // в цикле набиваем продукты случайными данными. имя вот только фиксированное. 
													//можно с клавы принять значения если не лень вводить. или написать генератор с преобразователем типов
		warehouse->Goods[i].price = 10 + i;
		warehouse->Goods[i].weight = 22 + i;

	}

	//выводим на экран

	for (i = 0; i < warehouse->size; i++) {
		cout << "Product : " << warehouse->Goods[i].name << " ";
		cout << "price : " << warehouse->Goods[i].price << " ";
		cout << "weight : " << warehouse->Goods[i].weight << endl;

	}


	cout << "SUM  : " << warehouse->getSumAll() << endl;
	cout << "unitSumMaxWeight : " << warehouse->getUnitSumMaxWeight(unsigned int getMaxWeightSum(), unsigned int getSumAll()) << endl;


	delete warehouse;

	return 0;

}