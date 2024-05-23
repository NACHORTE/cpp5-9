#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data ptr_1;
	uintptr_t ptr_2;

	ptr_1.s1 = "Hello, World!";
	ptr_1.n = 42;

	ptr_2 = Serializer::serialize(&ptr_1);
	std::cout << "Serialized pointer: " << ptr_2 << std::endl;
	std::cout << "Original pointer:   " << reinterpret_cast<std::size_t>(&ptr_1) << std::endl;

	Data *ptr_3 = Serializer::deserialize(ptr_2);

	std::cout << std::endl;

	std::cout << "Deserialized pointer: " << reinterpret_cast<std::size_t>(ptr_3) << std::endl;
	std::cout << "Original pointer:     " << reinterpret_cast<std::size_t>(&ptr_1) << std::endl;
	return 0;
}