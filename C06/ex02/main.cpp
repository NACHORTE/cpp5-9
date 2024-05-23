#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>

Base *generate()
{
	srand(time(NULL));
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify (Base *p)
{
	if (dynamic_cast<A*>(p))
		return (std::cout << "A"<<std::endl, void());
	if (dynamic_cast<B*>(p))
		return (std::cout << "B"<<std::endl, void());
	if (dynamic_cast<C*>(p))
		return (std::cout << "C"<<std::endl, void());
	std::cout << "Unknown type" << std::endl;
}

void identify (Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		return (std::cout << "A"<<std::endl, void());
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		return (std::cout << "B"<<std::endl, void());
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		return (std::cout << "C"<<std::endl, void());
	}
	catch(...)
	{}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	Base *obj = generate();

	std::cout << "Obj as pointer" << std::endl;
	identify(obj);
	std::cout << "\n";
	std::cout << "Obj as reference" << std::endl;
	identify(*obj);
	std::cout << "\n";
	delete obj;

	std::cout << "Using identify with NULL" << std::endl;
	identify (NULL);
	std::cout << "\n";


	A a;
	B b;
	C c;
	Base base;

	std::cout <<  "Type of A: " ;
	identify(a);
	std::cout <<  "Type of B: " ;
	identify(b);
	std::cout <<  "Type of C: " ;
	identify(c);
	std::cout <<  "Type of Base: " ;
	identify(base);

}