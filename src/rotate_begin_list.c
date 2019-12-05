/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** rotate_begin_list.c
*/

#include "push_swap.h"

static void rotate_toward_beginning(list_t **list)
{
    long nb = (*list)->data;

    my_delete_node(list, 0, 0);
    my_append_to_list(list, nb);
}

void rotate_begin_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "ra";

    rotate_toward_beginning(l_a);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void rotate_begin_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "rb";

    rotate_toward_beginning(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void rotate_begin_both(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "rr";

    rotate_toward_beginning(l_a);
    rotate_toward_beginning(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}