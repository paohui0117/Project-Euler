#pragma once
#include <math.h>
inline bool Isprime(int n)
{
	if (n < 2)
		return false;
	if (n < 4)
		return true;
	if (n & 1 == 0)
		return true;
	int nn = sqrt(n);
	nn++;
	for (size_t i = 2; i < nn; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

inline int GetDigit(int n)
{
	int ret = 0;
	if (n < 0)
		return 0;
	while (n > 0)
	{
		ret++;
		n /= 10;
	}
	return ret;
}
