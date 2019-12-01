/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** compare_functions.c
*/

#include "push_swap.h"

int list_sorted(list_t *list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL) {
        if (list->data > list->next->data)
            return (0);
        list = list->next;
    }
    return (1);
}

int list_reverse_sorted(list_t *list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL) {
        if (list->data < list->next->data)
            return (0);
        list = list->next;
    }
    return (1);
}