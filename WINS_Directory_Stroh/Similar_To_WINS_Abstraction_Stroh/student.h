#pragma once
#include "person.h"
#include <iostream>
#include <string>

class student : public virtual person
{
protected:
	std::string major;
	std::string minor;
	double gpa;

public:

	student(std::string first_name, std::string last_name, int id, std::string major, std::string minor, double gpa) : person(first_name, last_name, id)
	{
		this->major = major;
		this->minor = minor;
		this->gpa = gpa;
	}

	//GETS
	std::string get_major()
	{
		return major;
	}
	std::string get_minor()
	{
		return minor;
	}
	double get_gpa()
	{
		return gpa;
	}

	//SETS
	void set_major(std::string major)
	{
		if (major.length() > 0)
		{
			this->major = major;
		}
	}
	void set_minor(std::string minor)
	{
		if (minor.length() > 0)
		{
			this->minor = minor;
		}
	}
	void set_gpa(double gpa)
	{
		if (gpa >= 0 && gpa <= 4)
		{
			this->gpa = gpa;
		}
	}

	//PRINT
	void print() override
	{
		std::cout << last_name << ", " << first_name << " (" << id << ") [" << major << " Major / " << minor << " Minor] GPA: " << gpa << "\n";
	}
};