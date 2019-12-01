/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** verbose.c
*/

#include "push_swap.h"

void print_verbose(list_t **l_a, list_t **l_b, action_t *actions)
{
    if (actions->verbose) {
        my_putstr((char *)(my_node(*(actions->list), -1)->data));
        my_putchar('\n');
        my_putstr("l_a: ");
        print_list(*l_a);
        my_putstr("l_b: ");
        print_list(*l_b);
        my_putchar('\n');
    }
}