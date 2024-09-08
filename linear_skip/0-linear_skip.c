#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL;

	if (!list)
		return (NULL);

	while (list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				list->express->index, list->express->n);
		if (list->express->n >= value)
		{
			/* Found the block of the value */
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, list->express->index);
			break;
		}
		list = list->express;
	}
	if (!list->express && list->n < value)
	{
		prev = list;
		while (list->next)
		{
			prev = list;
			list = list->next;
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, list->index);
	}
	/* Traverse regular list */
	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		if (list->n > value)
			return (NULL);
		list = list->next;
	}
	return (NULL);
}
