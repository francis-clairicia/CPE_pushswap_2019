/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** bubble_sort.c
*/

#include "push_swap.h"

static int continue_sort_list(list_t **l_a, list_t **l_b)
{
    if (*l_b != NULL)
        return (1);
    return (!list_sorted(*l_a));
}

static void sort_int_list(list_t **l_a, list_t **l_b, list_t **actions)
{
    if ((*l_a)->data > (*l_a)->previous->data) {
        rotate_end_list_a(l_a, actions);
        return;
    }
    if (do_swap_both(l_a, l_b)) {
        swap_both(l_a, l_b, actions);
        return;
    } if (do_swap_b(l_b)) {
        swap_list_b(l_b, actions);
        return;
    } if (*l_a == NULL || (list_sorted(*l_a) && (*l_b) != NULL)) {
        push_to_list_a(l_a, l_b, actions);
        return;
    } if (do_swap_a(l_a))
        swap_list_a(l_a, actions);
    else
        push_to_list_b(l_a, l_b, actions);
}

void bubble_sort(list_t **l_a, list_t **l_b, list_t **actions, int verbose)
{
    while (continue_sort_list(l_a, l_b)) {
        sort_int_list(l_a, l_b, actions);
        if (verbose) {
            my_putstr((char *)(my_node(*actions, -1)->data));
            my_putchar('\n');
            my_putstr("l_a: ");
            print_list(*l_a);
            my_putstr("l_b: ");
            print_list(*l_b);
            my_putchar('\n');
        }
    }
}