#pragma once
#include "person.h"
#include <iostream>
#include <string>

class employee : public virtual person
{
protected:
	double salary;

public:
	employee(std::string first_name, std::string last_name, int id, double salary) : person(first_name, last_name, id)
	{
		this->salary = salary;
	}

	//GETS
	double get_salary()
	{
		return salary;
	}

	//SETS
	void set_salary(double salary)
	{
		if (salary > 1000)
		{
			this->salary = salary;
		}
	}
};