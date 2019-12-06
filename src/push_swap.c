/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_swap.c
*/

#include "push_swap.h"

static int list_sorted(list_t *list, int nb_int)
{
    if (nb_int == 1)
        return (1);
    while (list->next != NULL) {
        if (list->data > list->next->data)
            return (0);
        list = list->next;
    }
    return (1);
}

static void print_actions(list_t **actions)
{
    int size = 0;
    char *to_print = my_concat_str_list(*actions, ' ', &size);

    write(1, to_print, size);
    write(1, "\n", 1);
    free(to_print);
    my_free_list(actions, 0);
}

void push_swap(list_t **l_a, int nb_int, int verbose)
{
    list_t *l_b = NULL;
    list_t *action_list = NULL;
    action_t actions = {&action_list, nb_int, 0, verbose, 0};

    if (!list_sorted(*l_a, nb_int))
        insertion_sort(l_a, &l_b, &actions);
    print_actions(&action_list);
    my_free_list(&l_b, 0);
}