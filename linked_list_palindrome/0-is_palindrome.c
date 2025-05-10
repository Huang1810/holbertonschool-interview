#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to the head of the list
 * Return: pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *reversed_half;
    
    if (!head || !*head || !(*head)->next)
        return (1);

    // Find middle (slow ends in middle)
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse second half
    second_half = (fast == NULL) ? slow : slow->next;
    reversed_half = reverse_list(second_half);

    // Compare halves
    listint_t *first_half = *head, *check = reversed_half;
    int palindrome = 1;

    while (check)
    {
        if (first_half->n != check->n)
        {
            palindrome = 0;
            break;
        }
        first_half = first_half->next;
        check = check->next;
    }

    // Restore the list (optional)
    reverse_list(reversed_half);

    return palindrome;
}
