#ifndef REGEX_H
#define REGEX_H

#include <stdlib.h>
#include <stdio.h>

/**
 * regex_match - Checks if the string matches the pattern.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
