#pragma once
#include <iostream>
#include <climits>
#include <string>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

class Stack
{
private:
	int max_stack_size, top_of_stack;
	int* stack;

public:
	Stack(int max_stack_size) 
	{
		if (max_stack_size <= 0)
		{
			cout << "Stack size should be a positive integer!\n";
		}
		else
		{
			this->max_stack_size = max_stack_size;
			top_of_stack = -1;
			stack = new int[max_stack_size];
		}
	}
	
	~Stack()
	{
		delete[] stack;
	}

	//stack is the array we are using --> max_stack_size is already equal to array size
	void push(int value)
	{
		//IS LENGTH DIFFERENT THAN top_of_stack OR max_stack_size??
		//int length == number of items in stack
		if (top_of_stack == top_of_stack - 1)
		{
			cout << "Stack is full\n";
		}
		else
		{
			stack[++top_of_stack] = value;
		}
	}

	int pop()
	{
		if (top_of_stack == -1)
		{
			cout << "Stack is empty\n";
			//Returning a Junk Value
			return -999;
		}
		else
		{
			return stack[top_of_stack--];
		}
	}

	int size()
	{
		return (top_of_stack + 1);
	}

	string toString()
	{
		if (size() == 0)
		{
			return "[]";
		}
		string out = "[";
		for (int i = 0; i < top_of_stack; i++)
		{
			out += to_string(stack[i]);
			out += ", ";
		}
		out += to_string(stack[top_of_stack]);
		out += "]";
		return out;
	}
};

#endif