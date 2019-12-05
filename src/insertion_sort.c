/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** insertion_sort.c
*/

#include "push_swap.h"

static void put_all_in_list_b(list_t **l_a, list_t **l_b, action_t *actions)
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
}

static void sort_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    while ((*l_a)->next != NULL && (*l_a)->data > (*l_a)->next->data) {
        swap_list_a(l_a, l_b, actions);
        if ((*l_a)->next->next == NULL)
            continue;
        if ((*l_a)->next->data <= (*l_a)->next->next->data)
            continue;
        rotate_begin_list_a(l_a, l_b, actions);
        actions->nb_rotate += 1;
    }
    while (actions->nb_rotate > 0 && (*l_b != NULL)
    && (*l_a)->data >= (*l_b)->data && (*l_a)->previous->data > (*l_b)->data) {
        rotate_end_list_a(l_a, l_b, actions);
        actions->nb_rotate -= 1;
    }
}

void insertion_sort(list_t **l_a, list_t **l_b, action_t *actions)
{
    put_all_in_list_b(l_a, l_b, actions);
    while (*l_b != NULL) {
        push_to_list_a(l_a, l_b, actions);
        sort_list_a(l_a, l_b, actions);
    }
    if (actions->nb_rotate <= (actions->nb_int) / 2) {
        while (actions->nb_rotate > 0) {
            rotate_end_list_a(l_a, l_b, actions);
            actions->nb_rotate -= 1;
        }
    } else {
        while (actions->nb_rotate < actions->nb_int) {
            rotate_begin_list_a(l_a, l_b, actions);
            actions->nb_rotate += 1;
        }
    }
}