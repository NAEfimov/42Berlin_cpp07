/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:10:00 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/13 20:10:00 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		Array(void)
			: _elements(NULL), _size(0)
		{
		}

		explicit Array(unsigned int n)
			: _elements(NULL), _size(n)
		{
			if (_size != 0)
				_elements = new T[_size]();
		}

		Array(const Array &other)
			: _elements(NULL), _size(other._size)
		{
			if (_size != 0)
				_elements = new T[_size];
			for (unsigned int index = 0; index < _size; ++index)
				_elements[index] = other._elements[index];
		}

		~Array(void)
		{
			delete [] _elements;
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				T *newElements = NULL;

				if (other._size != 0)
				{
					newElements = new T[other._size];
					for (unsigned int index = 0; index < other._size; ++index)
						newElements[index] = other._elements[index];
				}
				delete [] _elements;
				_elements = newElements;
				_size = other._size;
			}
			return *this;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		const T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		unsigned int size(void) const
		{
			return _size;
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return "Array index out of bounds";
				}
		};

	private:
		T				*_elements;
		unsigned int	_size;
};

#endif
