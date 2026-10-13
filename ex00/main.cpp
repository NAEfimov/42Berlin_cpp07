/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:44:14 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/13 19:44:15 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>
#include <string>

namespace
{
    const char *const COLOR_RED = "\033[31m";
    const char *const COLOR_GREEN = "\033[32m";
    const char *const COLOR_CYAN = "\033[36m";
    const char *const COLOR_RESET = "\033[0m";

    bool check(bool condition, const std::string &message)
    {
        if (!condition)
            std::cerr << COLOR_RED << "FAIL:" << COLOR_RESET << " "
                      << message << std::endl;
        return condition;
    }

    int test_integers()
    {
        std::cout << COLOR_CYAN << "<<< Run test_integers >>>"
                  << COLOR_RESET << std::endl;
        int a = 2;
        int b = 3;
        std::cout << "a: " << a << " | b: " << b << std::endl;
        
        std::cout << "*swap*" << std::endl;
        ::swap(a, b);
        std::cout << "a: " << a << " | b: " << b << std::endl;
        if (!check(a == 3 && b == 2, "swap exchanges integers"))
            return 0;
        
        std::cout << "min(a, b): " << ::min(a, b) << std::endl;
        if (!check(::min(a, b) == 2, "min returns the smaller integer"))
            return 0;
        
        std::cout << "max(a, b): " << ::max(a, b) << std::endl;
        if (!check(::max(a, b) == 3, "max returns the larger integer"))
            return 0;
        return 1;
    }

    int test_equal_float()
    {
        std::cout << COLOR_CYAN << "<<< Run test_equal_float >>>"
                  << COLOR_RESET << std::endl;
        float equal_left = 7.4f;
        float equal_right = 7.4f;
        std::cout << "equal_left: " << equal_left
                  << " | equal_right: " << equal_right << std::endl;
        
        std::cout << "min(equal_left, equal_right): "
                  << ::min(equal_left, equal_right) << std::endl;
        if (!check(&::min(equal_left, equal_right) == &equal_right,
                "min returns the second equal argument"))
            return 0;
        
        std::cout << "max(equal_left, equal_right): "
                  << ::max(equal_left, equal_right) << std::endl;
        if (!check(&::max(equal_left, equal_right) == &equal_right,
                "max returns the second equal argument"))
            return 0;
        return 1;
    }

    int test_strings()
    {
        std::cout << COLOR_CYAN << "<<< Run test_strings >>>"
                  << COLOR_RESET << std::endl;
        std::string c = "message1";
        std::string d = "message2";
        std::cout << "c: " << c << " | d: " << d << std::endl;

        std::cout << "*swap*" << std::endl;
        ::swap(c, d);
        std::cout << "c: " << c << " | d: " << d << std::endl;
        if (!check(c == "message2" && d == "message1",
                "swap exchanges strings"))
            return 0;

        std::cout << "min(c, d): " << ::min(c, d) << std::endl;
        if (!check(::min(c, d) == "message1", "min compares strings"))
            return 0;

        std::cout << "max(c, d): " << ::max(c, d) << std::endl;
        if (!check(::max(c, d) == "message2", "max compares strings"))
            return 0;
        return 1;
    }
}

int main(void)
{
	if (!test_integers())
        return 1;

	if (!test_equal_float())
        return 1;

	if (!test_strings())
        return 1;

	std::cout << COLOR_GREEN << "All Exercise 00 tests passed."
              << COLOR_RESET << std::endl;
	return 0;
}
