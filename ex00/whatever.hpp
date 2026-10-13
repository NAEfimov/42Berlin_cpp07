/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:44:09 by nefimov           #+#    #+#             */
/*   Updated: 2026/10/13 19:44:10 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temporary = a;
	a = b;
	b = temporary;
}

template <typename T>
const T &min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
}

#endif
