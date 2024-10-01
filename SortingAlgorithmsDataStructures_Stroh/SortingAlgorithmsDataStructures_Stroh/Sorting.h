#pragma once
#include <iostream>
using namespace std;

#ifndef SORTING_H_
#define SORTING_H_

class Sorting
{
public:

	void selectionSort(int array[], int array_length)
	{
		for (int i = 0; i <= array_length - 2; i++)
		{
			int min_index = i;
			int temp = array[i];
			for (int j = i + 1; j <= array_length - 1; j++)
			{
				if (array[j] < array[min_index])
				{
					min_index = j;
				}
			}
			array[i] = array[min_index];
			array[min_index] = temp;
		}
	}

	void insertionSort(int array[], int array_length)
	{
		for (int i = 1; i <= array_length - 1; i++)
		{
			int j = i;
			int temp = array[j];
			while (j > 0 && temp < array[j-1])
			{
				array[j] = array[j - 1];
				j--;
			}
			array[j] = temp;
		}
	}

	void printArray(int A[], int length)
	{
		cout << "[";
		for (int i = 0; i < length - 1; i++)
		{
			cout << A[i] << ", ";
		}
		cout << A[length - 1] << "]";
	}
};
#endif