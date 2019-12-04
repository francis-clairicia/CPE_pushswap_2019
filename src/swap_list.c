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