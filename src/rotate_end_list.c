/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** rotate_end_list.c
*/

#include "push_swap.h"

static int rotate_toward_end(list_t **list)
{
    if (my_list_size(*list) < 2)
        return (0);
    my_put_in_list(list, (my_node(*list, -1))->data);
    my_delete_node(list, -1, 0);
    return (1);
}

void rotate_end_list_a(list_t **l_a, list_t **actions)
{
    if (rotate_toward_end(l_a))
        my_append_to_list(actions, (long)my_strdup("rra"));
}

void rotate_end_list_b(list_t **l_b, list_t **actions)
{
    if (rotate_toward_end(l_b))
        my_append_to_list(actions, (long)my_strdup("rrb"));
}

void rotate_end_both(list_t **l_a, list_t **l_b, list_t **actions)
{
    if (rotate_toward_end(l_a) || rotate_toward_end(l_b))
        my_append_to_list(actions, (long)my_strdup("rrr"));
}