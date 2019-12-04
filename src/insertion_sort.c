/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** insertion_sort.c
*/

#include "push_swap.h"

void insertion_sort(list_t **l_a, list_t **l_b, action_t *actions)
{
    while ((*l_a)->next != (*l_a)->previous) {
        if ((*l_a)->previous->data <= (*l_a)->data)
            rotate_end_list_a(l_a, l_b, actions);
        else
            push_to_list_b(l_a, l_b, actions);
        if (*l_b != NULL && (*l_b)->next != NULL
        && (*l_b)->data < (*l_b)->next->data)
            swap_list_b(l_a, l_b, actions);
    }
    if ((*l_a)->data > (*l_a)->next->data)
        swap_list_a(l_a, l_b, actions);
    while (*l_b != NULL) {
        push_to_list_a(l_a, l_b, actions);
        if ((*l_a)->data > (*l_a)->next->data)
            swap_list_a(l_a, l_b, actions);
    }
}