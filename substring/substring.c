#include "substring.h"


/**
 * find_substring - Finds all the possible substrings
 * containing a list of words, within a given string
 *
 * @s: string to scan
 * @words: the array of words all substrings
 * @nbWords: the number of elements in the array words
 * @n: Address at which to store the number of elements in the returned array
 * Return: An allocated array, or NULL on failure
 */
int *find_substring(const char *s, const char **words, int nbWords, int *n)
{
	int sLen = strlen(s), wordLen = strlen(words[0]);
	int totalLen = wordLen * nbWords, count = 0;
	int *indices = malloc(sLen * sizeof(int));
	int *used = malloc(nbWords * sizeof(int));

	for (int i = 0; i <= sLen - totalLen; i++)
	{
		for (int k = 0; k < nbWords; k++)
			used[k] = 0;
		int found = 1;

		for (int j = 0; j < nbWords; j++)
		{
			const char *currentWord = s + i + j * wordLen;
			int wordFound = 0;

			for (int k = 0; k < nbWords; k++)
			{
				if (!used[k] && strncmp(currentWord, words[k], wordLen) == 0)
				{
					used[k] = 1, wordFound = 1;
					break;
				}
			}
			if (!wordFound)
			{
				found = 0;
				break;
			}
		}
		if (found)
			indices[count++] = i;
	}
	free(used), *n = count;
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
