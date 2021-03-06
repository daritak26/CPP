/*Напишите программу, проверяющую последовательность скобок на корректность. В последовательности встречаются 3 вида скобок: ( ),{ },[ ].
Скобочная последовательность называется корректной, если каждая скобка закрыта соответствующей.
*/

#include "pch.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Brackets(char open, char close)
{
	if (open == '(' && close == ')') {
		return true;
	}
	else {
		if (open == '[' && close == ']') {
			return true;
		}
		else {
			if (open == '{' && close == '}') {
				return true;
			}
		}
	return false;
}

bool Balance(string abc)
{
	stack<char> A;
	for (int i = 0; i < abc.length(); i++)
	{
		if (abc[i] == '(' || abc[i] == '{' || abc[i] == '[') {
			A.push(abc[i]);
		}
		else {
			if (abc[i] == ')' || abc[i] == '}' || abc[i] == ']')
			{
				if (A.empty() || !Brackets(A.top(), abc[i])) {
					return false;
				}
				else {
					A.pop();
				}
			}
		}
	}
	return A.empty();
}
