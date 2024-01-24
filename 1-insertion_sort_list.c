#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after every swapping.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node;

    if (list == NULL || (*list) == NULL || (*list)->next == NULL)
        return;

    node = (*list)->next;

    while (node)
    {
        listint_t *current = node;

        while ((current->prev) && (current->prev->n > current->n))
        {
            listint_t *back = current->prev;

            back->next = current->next;
            if (current->next)
                current->next->prev = back;

            current->next = back;
            current->prev = back->prev;
            back->prev = current;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);
        }

        node = node->next;
    }
}

