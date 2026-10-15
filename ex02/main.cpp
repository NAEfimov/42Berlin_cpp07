/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:10:00 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/15 12:08:12 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>
#include <string>

static int check(bool condition, const char *message)
{
	if (!condition)
	{
		std::cerr << "[FAIL] " << message << std::endl;
		return 1;
	}
	std::cout << "[PASS] " << message << std::endl;
	return 0;
}

int main(void)
{
	std::cout << "=== Array test suite ===" << std::endl;
	std::cout << std::endl;
	std::cout << "Construction and size" << std::endl;
	Array<int> empty;
	if (check(empty.size() == 0, "empty array has size zero"))
		return 1;
	std::cout << "  empty.size() = " << empty.size() << std::endl;

	Array<int> numbers(3);
	if (check(numbers.size() == 3, "sized array reports its size"))
		return 1;
	std::cout << "  numbers.size() = " << numbers.size() << std::endl;
	if (check(numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0,
			  "fundamental elements are value-initialized"))
		return 1;
	std::cout << "  numbers = [" << numbers[0] << ", " << numbers[1] << ", "
			  << numbers[2] << "]" << std::endl;

	std::cout << std::endl
			  << "Copy construction" << std::endl;
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;
	std::cout << "  original = [" << numbers[0] << ", "
			  << numbers[1] << ", " << numbers[2] << "]" << std::endl;
	Array<int> copied(numbers);
	numbers[0] = 100;
	std::cout << "  original after modification = [" << numbers[0] << ", "
			  << numbers[1] << ", " << numbers[2] << "]" << std::endl;
	std::cout << "  copy remains = [" << copied[0] << ", " << copied[1] << ", "
			  << copied[2] << "]" << std::endl;
	if (check(copied[0] == 10, "copy constructor performs a deep copy"))
		return 1;

	std::cout << std::endl
			  << "Assignment and self-assignment" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	std::cout << "  source = [" << numbers[0] << ", "
			  << numbers[1] << ", " << numbers[2] << "]" << std::endl;
	numbers[1] = 200;
	std::cout << "  source after modification = [" << numbers[0] << ", "
			  << numbers[1] << ", " << numbers[2] << "]" << std::endl;
	std::cout << "  assigned copy = [" << assigned[0] << ", " << assigned[1]
			  << ", " << assigned[2] << "]" << std::endl;
	if (check(assigned.size() == 3 && assigned[1] == 20,
			  "assignment performs a deep copy"))
		return 1;
	assigned = assigned;
	if (check(assigned[0] == 100, "self-assignment preserves the array"))
		return 1;

	std::cout << std::endl
			  << "Const and non-fundamental access" << std::endl;
	const Array<int> readOnly(numbers);
	std::cout << "  const array element [2] = " << readOnly[2] << std::endl;
	if (check(readOnly[2] == 30, "const arrays can be indexed"))
		return 1;

	Array<std::string> words(2);
	words[0] = "first";
	words[1] = "second";
	std::cout << "  words = [\"" << words[0] << "\", \"" << words[1]
			  << "\"]" << std::endl;
	if (check(words[0] == "first" && words[1] == "second",
			  "arrays support non-fundamental types"))
		return 1;

	std::cout << std::endl
			  << "Bounds checking" << std::endl;
	bool threw = false;
	try
	{
		empty[0] = 1;
	}
	catch (const std::exception &exception)
	{
		threw = (std::string(exception.what()) == "Array index out of bounds");
		std::cout << "  empty[0] threw: " << exception.what() << std::endl;
	}
	if (check(threw, "out-of-bounds access throws std::exception"))
		return 1;

	threw = false;
	try
	{
		numbers[3];
	}
	catch (const std::exception &)
	{
		threw = true;
		std::cout << "  numbers[3] threw an exception" << std::endl;
	}
	if (check(threw, "upper-bound access throws"))
		return 1;

	std::cout << std::endl
			  << "=== All Array tests passed ===" << std::endl;
	return 0;
}
