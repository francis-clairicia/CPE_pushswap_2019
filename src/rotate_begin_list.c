/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** rotate_begin_list.c
*/

#include "push_swap.h"

static void rotate_toward_beginning(list_t **list)
{
    my_append_to_list(list, (*list)->data);
    my_delete_node(list, 0, 0);
}

void rotate_begin_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    rotate_toward_beginning(l_a);
    my_append_to_list(actions->list, (long)my_strdup("ra"));
    print_verbose(l_a, l_b, actions);
}

void rotate_begin_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    rotate_toward_beginning(l_b);
    my_append_to_list(actions->list, (long)my_strdup("rb"));
    print_verbose(l_a, l_b, actions);
}

void rotate_begin_both(list_t **l_a, list_t **l_b, action_t *actions)
{
    rotate_toward_beginning(l_a);
    rotate_toward_beginning(l_b);
    my_append_to_list(actions->list, (long)my_strdup("rr"));
    print_verbose(l_a, l_b, actions);
}