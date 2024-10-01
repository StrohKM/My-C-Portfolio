#pragma once
#include "employee.h"
#include "student.h"
#include <iostream>

class graduate_student : public employee, public student
{
public:
	graduate_student(std::string first_name, std::string last_name, int id, std::string major, std::string minor, double gpa, double salary) : student(first_name, last_name, id, major, minor, gpa), employee(first_name, last_name, id, salary), person(first_name, last_name, id)
	{

	}
	
	//PRINT
	void print() override
	{
		std::cout << last_name << ", " << first_name << " (" << id << ") [" << major << " Major] GPA: " << gpa << " ($" << salary << ")\n";
	}
};