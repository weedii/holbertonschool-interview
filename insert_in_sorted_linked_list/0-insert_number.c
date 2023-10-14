#include "lists.h"

/**
 * insert_node - function that ...
 * @head: pointer to the adress of the first node
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current, *prev, *new_node;

    new_node = malloc(sizeof(listint_t));
    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current = *head;
    prev = NULL;

    while (current != NULL && current->n < number)
    {
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;

    return new_node;
}