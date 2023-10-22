#include "palindrome.h"

/**
 * is_palindrome - function that checks whether
 *      or not a given unsigned integer is a palindrome.
 * @n:      number to be checked
 * Return:  return 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long x = n;
	unsigned long reverse = 0;

	while (n > 0)
	{
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	return ((x == reverse) ? 1 : 0);
}
