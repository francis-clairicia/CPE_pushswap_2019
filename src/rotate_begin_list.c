/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** rotate_begin_list.c
*/

#include "push_swap.h"

static int rotate_toward_beginning(list_t **list)
{
    if (my_list_size(*list) < 2)
        return (0);
    my_append_to_list(list, (my_node(*list, 0))->data);
    my_delete_node(list, 0, 0);
    return (1);
}

void rotate_begin_list_a(list_t **l_a, list_t **actions)
{
    if (rotate_toward_beginning(l_a))
        my_append_to_list(actions, (long)my_strdup("ra"));
}

void rotate_begin_list_b(list_t **l_b, list_t **actions)
{
    if (rotate_toward_beginning(l_b))
        my_append_to_list(actions, (long)my_strdup("rb"));
}

void rotate_begin_both(list_t **l_a, list_t **l_b, list_t **actions)
{
    if (rotate_toward_beginning(l_a) || rotate_toward_beginning(l_b))
        my_append_to_list(actions, (long)my_strdup("rr"));
}