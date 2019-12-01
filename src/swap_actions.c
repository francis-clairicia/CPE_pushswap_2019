/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** swap_actions.c
*/

#include "push_swap.h"

int do_swap_a(list_t **l_a)
{
    if (*l_a == NULL)
        return (0);
    if ((*l_a)->next == NULL)
        return (0);
    return ((*l_a)->data > (*l_a)->next->data);
}

int do_swap_b(list_t **l_b)
{
    if (*l_b == NULL)
        return (0);
    if ((*l_b)->next == NULL)
        return (0);
    return ((*l_b)->data < (*l_b)->next->data);
}

int do_swap_both(list_t **l_a, list_t **l_b)
{
    return (do_swap_a(l_a) && do_swap_b(l_b));
}