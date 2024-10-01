#pragma once
#include <iostream>
#include <climits>
#include <string>
using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue
{
private:
	int max_queue_size, front, rear, current_size;
	int* queue;

public:
	Queue(int max_queue_size)
	{
		if (max_queue_size <= 0)
		{
			cout << "Queue size should be a positive integer.";
		}
		else
		{
			this->max_queue_size = max_queue_size;
			front = rear = 0;
			current_size = 0;
			queue = new int[max_queue_size];
		}
	}

	~Queue()
	{
		delete[] queue;
	}

	void enqueue(int value)
	{
		//front is supposed to be length, but how get length?
		if (current_size == max_queue_size)
		{
			cout << "Queue is full\n";
		}
		else
		{
			queue[rear++] = value;
			current_size++;
			//supposed to be rear == length, but I'm not sure if this is different
			if (rear == max_queue_size)
			{
				rear = 0;
			}
		}
	}

	int dequeue()
	{
		if (current_size == 0)
		{
			cout << "Queue is empty\n";
			return -999;
		}
		else
		{
			int y = queue[front++];
			current_size--;
			if (front == max_queue_size)
			{
				front = 0;
			}
			return y;
		}
	}

	int size()
	{
		return current_size;
	}

	string toString()
	{
		if (size() == 0)
		{
			return "[]";
		}
		else
		{
			string output = "[";
			if (rear > front)
			{
				for (int i = front; i < rear - 1; i++)
				{
					output += to_string(queue[i]) + ", ";
				}
				output += to_string(queue[rear - 1]) + "]";
			}
			else
			{
				for (int i = front; i < max_queue_size - 1; i++)
				{
					output += to_string(queue[i]) + ", ";
				}
				output += to_string(queue[max_queue_size - 1]);

				for (int i = 0; i < rear; i++)
				{
					output += ", " + to_string(queue[i]);
				}
				output += "]";
			}
			return output;
		}
	}
};

#endif