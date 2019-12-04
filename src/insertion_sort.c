/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** insertion_sort.c
*/

#include "push_swap.h"

static void switch_to_b(list_t **l_a, list_t **l_b,
    action_t *actions)
{
    while ((*l_a)->previous != *l_a) {
        if ((*l_a)->previous->data <= (*l_a)->data) {
            rotate_end_list_a(l_a, actions->list);
            print_verbose(l_a, l_b, actions);
        }
        push_to_list_b(l_a, l_b, actions->list);
        print_verbose(l_a, l_b, actions);
    }
}

static void switch_to_a(list_t **l_a, list_t **l_b,
    action_t *actions)
{
    while (*l_b != NULL) {
        push_to_list_a(l_a, l_b, actions->list);
        print_verbose(l_a, l_b, actions);
        if ((*l_a)->data > (*l_a)->next->data) {
            swap_list_a(l_a, actions->list);
            print_verbose(l_a, l_b, actions);
        }
    }
}

void insertion_sort(list_t **l_a, list_t **l_b, action_t *actions)
{
    switch_to_b(l_a, l_b, actions);
    switch_to_a(l_a, l_b, actions);
}