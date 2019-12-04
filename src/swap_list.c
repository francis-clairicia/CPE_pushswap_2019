/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** swap.c
*/

#include "push_swap.h"

static void swap_first_two_elements(list_t **list)
{
    list_t *first_node = NULL;
    list_t *second_node = NULL;
    long data;

    first_node = my_node(*list, 0);
    second_node = my_node(*list, 1);
    data = first_node->data;
    first_node->data = second_node->data;
    second_node->data = data;
}

void swap_list_a(list_t **l_a, list_t **l_b, action_t *actions)
{
    swap_first_two_elements(l_a);
    my_append_to_list(actions->list, (long)my_strdup("sa"));
    print_verbose(l_a, l_b, actions);
}

void swap_list_b(list_t **l_a, list_t **l_b, action_t *actions)
{
    swap_first_two_elements(l_b);
    my_append_to_list(actions->list, (long)my_strdup("sb"));
    print_verbose(l_a, l_b, actions);
}

void swap_both(list_t **l_a, list_t **l_b, action_t *actions)
{
    swap_first_two_elements(l_a);
    swap_first_two_elements(l_b);
    my_append_to_list(actions->list, (long)my_strdup("sc"));
    print_verbose(l_a, l_b, actions);
}