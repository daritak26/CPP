/*Реализуйте класс char_deque -  дек символов чисел переменного размера. Класс должен содержать конструктор, деструктор,
методы push_front, push_back,pop_front, pop_back*/


#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

template <typename T>

class char_deque
{
private:
	struct Node
	{
		Node* next = NULL;
		string data;
		Node* prev;
	};
	Node *head;
	Node* tail;
	int count;
public:
	void push_front(int x)
	{
		if (head == NULL)
		{
			head = new Node;
			tail = head;
			head->data = x;
			return;
		}
		head->prev = new Node;
		head->prev->next = head;
		head = head->prev;
		head->data = x;
	};

	void push_back(int x)
	{
		if (head == NULL)
		{
			tail = new Node;
			head = tail;
			tail->data = x;
			return;
		}
		tail->next = new Node;
		tail->next->prev = head;
		tail = tail->next;
		tail->data = x;
	};

	bool isEmpty()
	{
		return count == 0 ? true : false;
	}

	string pop_front()
	{
		string ret = head->data;

		Node* tmp = head;
		if (head->next != NULL)
		{
			head = head->next;
			head->prev = NULL;
		}
		else
		{
			head = NULL;
		}
		count--;
		delete tmp;

		return ret;
	}

	string pop_back()
	{
		string ret = tail->data;
		Node* tmp = tail;
		if (tail->prev != NULL)
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			tail = NULL;
		}
		count--;
		delete tmp;
		return ret;
	}
};

