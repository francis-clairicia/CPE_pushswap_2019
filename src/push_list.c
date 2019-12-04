/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_list.c
*/

#include "push_swap.h"

static void put_to_second_list(list_t **first, list_t **second)
{
    my_put_in_list(second, (my_node(*first, 0)->data));
    my_delete_node(first, 0, 0);
}

void push_to_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    put_to_second_list(l_b, l_a);
    my_append_to_list(actions->list, (long)my_strdup("pa"));
    print_verbose(l_a, l_b, actions);
}

void push_to_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    put_to_second_list(l_a, l_b);
    my_append_to_list(actions->list, (long)my_strdup("pb"));
    print_verbose(l_a, l_b, actions);
}