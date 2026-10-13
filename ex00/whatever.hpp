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
