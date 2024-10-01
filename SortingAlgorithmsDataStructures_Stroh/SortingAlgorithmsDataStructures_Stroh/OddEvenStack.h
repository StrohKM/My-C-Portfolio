#pragma once
#include <iostream>
#include <climits>
#include <string>
#include "Stack.h"
using namespace std;

#ifndef ODDEVENSTACK_H_
#define ODDEVENSTACK_H_

class OddEvenStack
{
private:
	//tos == top of stack
	int max_stack_size, odd_tos, even_tos;
	int* stack;

public:
	OddEvenStack(int max_stack_size)
	{
		if (max_stack_size <= 0)
		{
			cout << "Stack size should be a positive integer!\n";
		}
		else
		{
			this->max_stack_size = max_stack_size;
			odd_tos = -1;
			even_tos = max_stack_size;
			stack = new int[max_stack_size];
			for (int i = 0; i < max_stack_size; i++)
			{
				stack[i] = 0;
			}
		}
	}

	~OddEvenStack()
	{
		delete[] stack;
	}

	int size()
	{
		return (odd_tos + 1) + (max_stack_size - even_tos);
	}

	void push(int value)
	{
		if (max_stack_size == size())
		{
			cout << "Stack is full\n";
			return;
		}
		//int length == number of items in stack
		if (value % 2 == 1)
		{
			stack[++odd_tos] = value;
		}
		else
		{
			stack[--even_tos] = value;
		}

	}

	int popOdd()
	{
		if (odd_tos == -1)
		{
			cout << "Stack is empty\n";
			//Returning a Junk Value
			return -999;
		}
		else
		{
			return stack[odd_tos--];
		}
	}

	int popEven()
	{
		if (even_tos == max_stack_size)
		{
			cout << "Stack is empty\n";
			//Returning a Junk Value
			return -999;
		}
		else
		{
			return stack[even_tos++];
		}
	}

	string toString()
	{
		string out = "[";
		for (int i = 0; i < max_stack_size - 1; i++)
		{
			out += to_string(stack[i]) + ", ";
		}
		out += to_string(stack[max_stack_size - 1]) + "]";
		return out;
	}
};

#endif /*	ODDEVENSTACK_H_	*/
