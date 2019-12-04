/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** rotate_end_list.c
*/

#include "push_swap.h"

static void rotate_toward_end(list_t **list)
{
    my_put_in_list(list, (*list)->previous->data);
    my_delete_node(list, -1, 0);
}

void rotate_end_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "rra";

    rotate_toward_end(l_a);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void rotate_end_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "rrb";

    rotate_toward_end(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void rotate_end_both(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "rrr";

    rotate_toward_end(l_a);
    rotate_toward_end(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}