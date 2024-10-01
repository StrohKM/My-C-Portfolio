#include <iostream>
#include <string>	
#include "person.h"

person::person(std::string first_name, std::string last_name, int id)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->id = id;
}

//GETS
std::string person::get_first_name()
{
	return first_name;
}
std::string person::get_last_name()
{
	return last_name;
}
int person::get_id()
{
	return id;
}

//SETS
void person::set_first_name()
{
	if (first_name.length() > 0)
	{
		this->first_name = first_name;
	}
}
void person::set_last_name()
{
	if (last_name.length() > 0)
	{
		this->last_name = last_name;
	}
}
void person::set_id()
{
	if (id >= 0 && id <= 4.0)
	{
		this->id = id;
	}
}

