/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:51:00 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/13 20:03:08 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include <string>

void increment(int &value)
{
	++value;
}

void printInt(const int &value)
{
	std::cout << value << " ";
}

void printString(const std::string &value)
{
	std::cout << value << " ";
}

template <typename T>
void printValue(const T &value)
{
	std::cout << value << " ";
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4};
	const int expected[] = {2, 3, 4, 5};
	const int readOnlyNumbers[] = {10, 20, 30};
    const int empty[] = {};
	std::string words[] = {"one", "two", "three"};

	
    std::cout << "numbers: ";
	iter(numbers, sizeof(numbers) / sizeof(numbers[0]), printInt);
	std::cout << std::endl;
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), increment);
	for (std::size_t index = 0;
		index < sizeof(numbers) / sizeof(numbers[0]); ++index)
	{
		if (numbers[index] != expected[index])
			return 1;
	}

	std::cout << "iter numbers: ";
	iter(numbers, sizeof(numbers) / sizeof(numbers[0]), printInt);
	std::cout << std::endl;

	std::cout << "const numbers: ";
	iter(readOnlyNumbers,
		sizeof(readOnlyNumbers) / sizeof(readOnlyNumbers[0]), printValue<int>);
	std::cout << std::endl;

	std::cout << "words: ";
	iter(words, sizeof(words) / sizeof(words[0]), printString);
	std::cout << std::endl;

	std::cout << "empty: ";
	iter(empty, 0, printInt);
	std::cout << std::endl;
	std::cout << "done" << std::endl;

	return 0;
}
