/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_list.c
*/

#include "push_swap.h"

static void put_to_second_list(list_t **first, list_t **second)
{
    my_put_in_list(second, (*first)->data);
    my_delete_node(first, 0, 0);
}

void push_to_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "pa";

    put_to_second_list(l_b, l_a);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void push_to_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "pb";

    put_to_second_list(l_a, l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}