#ifndef __ITER_HPP__
# define __ITER_HPP__

# include <cstddef>

template < typename T >
void	iter(T* addr, size_t size, void (*f)(T&)) {

	size_t i;

	if (!addr || !f)
		return;

	for (i = 0; i < size; i++) {
		f(*(addr + i));
	}
}

#endif