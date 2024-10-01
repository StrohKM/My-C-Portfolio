#pragma once
#include "employee.h"

class instructor : public employee
{
private:
	std::string department;

public:
	instructor(std::string first_name, std::string last_name, int id, std::string department, double salary) : employee(first_name, last_name, id, salary), person(first_name, last_name, id)
	{
		this->department = department;
	}

	//GETS
	std::string get_department()
	{
		return department;
	}

	//SETS
	void set_department()
	{
		if (department.length() > 0)
		{
			this->department = department;
		}
	}

	//PRINT
	void print() override
	{
		std::cout << "Prof. " << last_name << " (" << id << ") [Dept. of " << department << "] ($" << salary << ")\n";
	}
};