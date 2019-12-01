/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_list.c
*/

#include "push_swap.h"

static int put_to_second_list(list_t **first, list_t **second)
{
    if (*first == NULL)
        return (0);
    my_put_in_list(second, (my_node(*first, 0)->data));
    my_delete_node(first, 0, 0);
    return (1);
}

void push_to_list_a(list_t **l_a, list_t **l_b, list_t **actions)
{
    if (put_to_second_list(l_b, l_a))
        my_append_to_list(actions, (long)my_strdup("pa"));
}

void push_to_list_b(list_t **l_a, list_t **l_b, list_t **actions)
{
    if (put_to_second_list(l_a, l_b))
        my_append_to_list(actions, (long)my_strdup("pb"));
}