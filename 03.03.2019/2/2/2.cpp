/*Реализуйте класс string_queue -  очередь строк. Класс должен содержать конструктор, деструктор, методы push,pop.*/

#include "pch.h"
#include <iostream>
#include <stack>
using namespace std;

template <typename T>

class string_queue
{
private:
	struct Node
	{
		Node* next = NULL;
		string data;
	};
	Node *head;
public:
	setlocale(LC_ALL, "Russian");
	string_queue()
	{
		head = NULL;
	}

	~string_queue()
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	};

	int pop()
	{
		if (head == NULL)
		{
			cout << "Пуста";
			return 0;
		}
		Node* temp = head;
		head = head->next;
		int x = temp->data;
		delete temp;
		return x;
	};
	void push(int x)
	{
		if (head == NULL)
		{
			head = new Node;
			head->data = x;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->data = x;
	};
};
