#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

int main()
{
	try
	{
		std::cout << "Creating an int array with default constructor" << std::endl;
		Array<int> zero_ints;
		std::cout << "zero_ints.size=" << zero_ints.size() << "\n";
		std::cout << std::endl;
		std::cout << "Trying to read pos[0]" << std::endl;
		try{
			std::cout << "zero_ints[0]="<<zero_ints[0]<<std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Creating float array f1 of size 5" << std::endl;
		Array<float> f1(5);
		for (size_t i = 0; i < 5; i ++)
			f1[i] = 10.0 /i;
		std::cout << "f1.size=" << f1.size() << "\n"; 
		for (size_t i = 0; i < 5; i ++)
			std::cout << "f1[" << i << "]=" << f1[i] << "\n";

		std::cout << std::endl;
		std::cout << "Creating f2 copied from f1" << std::endl;
		Array<float> f2 = f1;
		std::cout << "f2.size=" << f2.size() << "\n"; 
		for (size_t i = 0; i < 5; i ++)
			std::cout << "f2[" << i << "]=" << f2[i] << "\n";
		std::cout << std::endl;
		std::cout << "Modifying f2 to check deep copy" << std::endl;
		for (size_t i = 0; i < 5; i ++)
			f2[i] += 1.0 ;
		for (size_t i = 0; i < 5; i ++)
		{
			std::cout << "f1[" << i << "]=" << std::left << std::setw(15) << f1[i];
			std::cout <<" f2[" << i << "]=" << std::left << std::setw(15) << f2[i] << "\n";
		}
		std::cout << std::endl;
		std::cout << "Checking f2[6]" << std::endl;
		try
		{
			std::cout << "f2[0]="<<f2[6]<< std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}