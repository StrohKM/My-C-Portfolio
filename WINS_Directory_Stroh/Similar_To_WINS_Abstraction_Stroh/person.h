#pragma once

class person
{
protected:
	std::string first_name;
	std::string last_name;
	int id;

public:
	person(std::string first_name, std::string last_name, int id);

	//GETS
	std::string get_first_name();
	std::string get_last_name();
	int get_id();

	//SETS
	void set_first_name();
	void set_last_name();
	void set_id();

	//PRINT
	virtual void print()
	{
		std::cout << id << ": " << last_name << ", " << first_name << "\n";
	}
};