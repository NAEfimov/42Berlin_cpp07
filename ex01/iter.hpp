/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:51:00 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/13 20:03:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename Function>
void iter(T *array, const std::size_t length, Function function)
{
	std::size_t index = 0;

	while (index < length)
	{
		function(array[index]);
		++index;
	}
}

#endif
