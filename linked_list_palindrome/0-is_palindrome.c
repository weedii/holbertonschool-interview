#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * reverseList - Reverse a linkedlist
 * @head: pointer to head of list
 * Return: pointer to the new head of the reversed list
 */
listint_t* reverseList(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}


/**
 * is_palindrome - check if linkedlist is palindrome
 * @head: pointer to head of list
 * Return: 1 if it is linkedlist 0 if not
*/
int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    listint_t *p = *head;
    listint_t *q = *head;
    listint_t *startSecond = NULL;

    while(1) {
        p = p->next->next;
        if (p == NULL) {
            startSecond = q->next;
            break;
        }
        if (p->next == NULL)
        {
            startSecond = q->next->next;
            break;
        }
        q = q->next;
    }
    q->next=NULL;

    listint_t *firstHalf = *head;
    listint_t *secondHalf = startSecond;

    secondHalf = reverseList(secondHalf);

    // compare now
    while(secondHalf != NULL) {
        if (firstHalf->n != secondHalf->n) {
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
}
