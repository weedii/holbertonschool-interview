#include "holberton.h"

/**
 * wildcmp - Function that ompares two strings if they can be considered
 * identical.
 * @s1: The first string.
 * @s2: The second string, which can include the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2) {
  char *tmpS2 = NULL;
  char *match = NULL;

  while (*s1 != '\0') {
    printf("%c\n", *s2);
    if (*s2 == '*') {
      tmpS2 = s2++;
      match = s1;
    } else if (*s1 == *s2) {
      s1++;
      s2++;
    } else if (tmpS2) {
      s2 = tmpS2 + 1;
      s1 = ++match;
    } else {
      return 0;
    }
  }

  while (*s2 == '*')
    s2++;

  return (*s2 == '\0');
}
