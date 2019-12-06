/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** swap.c
*/

#include "push_swap.h"

static void swap_first_two_elements(list_t **list)
{
    long data = (*list)->data;

    (*list)->data = (*list)->next->data;
    (*list)->next->data = data;
}

void swap_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "sa";

    swap_first_two_elements(l_a);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void swap_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "sb";

    swap_first_two_elements(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}

void swap_both(list_t **l_a, list_t **l_b, action_t *actions)
{
    char *action = "sc";

    swap_first_two_elements(l_a);
    swap_first_two_elements(l_b);
    my_append_to_list(actions->list, (long)action);
    print_verbose(l_a, l_b, actions);
}