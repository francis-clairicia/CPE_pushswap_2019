/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** insertion_sort.c
*/

#include "push_swap.h"

static void switch_to_b(long nb, list_t **l_a, list_t **l_b,
    action_t *actions)
{
    if ((*l_a)->previous != *l_a
    && (*l_a)->previous->data <= (*l_a)->data) {
        rotate_end_list_a(l_a, actions->list);
        print_verbose(l_a, l_b, actions);
    } if ((*l_a)->data != nb) {
        push_to_list_b(l_a, l_b, actions->list);
        print_verbose(l_a, l_b, actions);
    }
}

static void switch_to_a(list_t **l_a, list_t **l_b,
    action_t *actions)
{
    push_to_list_a(l_a, l_b, actions->list);
    print_verbose(l_a, l_b, actions);
    if ((*l_a)->data > (*l_a)->next->data) {
        swap_list_a(l_a, actions->list);
        print_verbose(l_a, l_b, actions);
    }
}

static void sort_list(long nb, list_t **l_a, list_t **l_b,
    action_t *actions)
{
    while ((*l_a)->next->data != nb && (*l_a)->data != nb)
        switch_to_b(nb, l_a, l_b, actions);
    if ((*l_a)->previous != *l_a
    && (*l_a)->previous->data <= (*l_a)->data) {
        rotate_end_list_a(l_a, actions->list);
        print_verbose(l_a, l_b, actions);
        push_to_list_b(l_a, l_b, actions->list);
        print_verbose(l_a, l_b, actions);
    }
    if ((*l_a)->next->data == nb) {
        swap_list_a(l_a, actions->list);
        print_verbose(l_a, l_b, actions);
    }
    while (*l_b != NULL)
        switch_to_a(l_a, l_b, actions);
}

void insertion_sort(list_t **l_a, list_t **l_b, action_t *actions)
{
    list_t *node;

    node = (*l_a)->next;
    while (node != NULL) {
        if (node->previous->data > node->data)
            sort_list(node->data, l_a, l_b, actions);
        node = node->next;
    }
}