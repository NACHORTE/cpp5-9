#pragma once
#include <iostream>
#include <stdint.h>

struct Data
{
	std::string s1;
	int n;
};

class Serializer
{
	public:
	// Constructors and destructor
		~Serializer();

	// Setters and getters
		
	// Member functions
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	// Operator overloads
		Serializer & operator=(const Serializer & rhs);

	protected:
	private:
	Serializer(void);
	Serializer(const Serializer & src);
	// Atributes

	// Private member functions

};

std::ostream &operator<<(std::ostream &os, const Serializer &obj);
