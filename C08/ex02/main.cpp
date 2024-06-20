#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "SUBJECT TEST" << std::endl;
		std::cout << "Creating MutantStack" << std::endl;
		MutantStack<int> mstack;
		std::cout << "Pushing elements " << "17" << " and " << "5" << std::endl;
		mstack.push(17);
		mstack.push(5);
		std::cout << "top: "  << mstack.top() << std::endl;
		std::cout << "Popping one element" << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "Pushing elements " << "(3, 5, 737, 0)" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "Creating iterators and looping through stack" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Creating an std::stack from a Mutant stack" << std::endl;
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "SAME TEST WITH A LIST" << std::endl;
		std::cout << "Creating list" << std::endl;
		std::list<int> mstack;
		std::cout << "Pushing elements " << "17" << " and " << "5" << std::endl;
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "top: " << mstack.back() << std::endl;
		std::cout << "Popping one element" << std::endl;
		mstack.pop_back();
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "Pushing elements " << "(3, 5, 737, 0)" << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << "Creating iterators and looping through stack" << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		return 0;
	}
}