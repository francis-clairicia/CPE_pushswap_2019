/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** print_list.c
*/

#include "push_swap.h"

void print_list(list_t *list)
{
    while (list != NULL) {
        my_put_nbr(list->data);
        if (list->next != NULL)
            my_putchar(' ');
        list = list->next;
    }
    my_putchar('\n');
}