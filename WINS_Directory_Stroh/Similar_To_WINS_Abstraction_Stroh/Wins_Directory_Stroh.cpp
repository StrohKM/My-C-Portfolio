/*
Kayla Stroh
3/17/23
Similar to WINS Abstraction
Program similar to WINS that keeps track of student and faculty data
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "person.h"
#include "employee.h"
#include "instructor.h"
#include "student.h"
#include "graduate_student.h"

int main()
{
	const int arr_count = 6;

	person** people = new person * [arr_count]
	{
		new instructor("Mai", "Ikari", 9597823, "Robotics", 70000),
			new instructor("Jack", "Bowman", 5208963, "Neurology", 100000),
			new graduate_student("Mom", "Your", 1119620, "Monkey Business", "NONE", 3.6, 8000),
			new graduate_student("Amber", "Henschel", 1227195, "Education", "NONE", 3.9, 2000),
			new student("Rick", "Deckard", 1982019, "Criminology", "Psychology", 3.2),
			new student("Eleanor", "Arroway", 119620, "Astronomy", "Mathematics", 4.0),
	};

	//Prints out all people in array
	for (int i = 0; i < arr_count; i++)
	{
		people[i]->print();
	}

	std::cout << "\n";
	//Grad students only
	std::cout << "Graduate students:\n";
	for (int i = 0; i < arr_count; i++)
	{
		if (graduate_student* gs = dynamic_cast<graduate_student*>(people[i]))
		{
			gs->print();
		}
	}
	
	std::cout << "\nEmployee with highest salary: \n";
	//Issue for these is its trying to get salary from people who are not employees if they are starting in the array
	employee* highest_paid = dynamic_cast<employee*>(people[0]);
	if (highest_paid->get_salary())
	{
		for (int i = 1; i < arr_count; i++)
		{
			employee* emp = dynamic_cast<employee*>(people[i]);
			if (emp && emp->get_salary() > highest_paid->get_salary())
			{
				highest_paid = emp;
			}
		}
	}
	highest_paid->print();

	std::cout << "\nEmployee with lowest salary: \n";
	employee* lowest_paid = dynamic_cast<employee*>(people[0]);
	for (int i = 1; i < arr_count; i++)
	{
		if (employee* emp = dynamic_cast<employee*>(people[i]))
		{
			if (emp && emp->get_salary() < lowest_paid->get_salary())
			{
				lowest_paid = emp;
			}
		}
	}
	lowest_paid->print();

	delete[] people;
	return 0;
}