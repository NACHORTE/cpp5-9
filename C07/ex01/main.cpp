#include <cstddef>
#include <iostream>

#include "iter.hpp"

class Test {
	private:
		int _age;
	public:
		Test();
		Test(const Test&);
		Test& operator=(const Test&);
		~Test();
		static void sayHello(Test&);
};

Test::~Test() {}

Test::Test()
	:_age(1)
{

	std::cout << "constructor called" << std::endl;
}

Test::Test(const Test& other) {
  *this = other;
}

Test& Test::operator=(const Test& rhs) {
  if (this != &rhs) this->_age = rhs._age;
  return *this;
}

void	incr(int& n) {
	++n;
}

void print(int& n) {
  std::cout << n << " ";
}

int main() {
	int arr[4] = {1, 2, 3, 4};

  iter(arr, 4, &print);
	std::cout << std::endl;

	iter(arr, 4, &incr);

  iter(arr, 4, &print);
	std::cout << std::endl;

	iter((int*)NULL, 100, &incr);

	std::cout << "I did not crash!" << std::endl;

	return 0;
}