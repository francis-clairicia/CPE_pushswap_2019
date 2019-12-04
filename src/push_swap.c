/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_swap.c
*/

#include "push_swap.h"

static list_t *my_params_to_list(int nb_int, char **nb_list)
{
    list_t *list = NULL;
    int i = 0;

    while (i < nb_int) {
        my_append_to_list(&list, my_getnbr(nb_list[i]));
        i += 1;
    }
    return (list);
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

list_t *push_swap(int nb_int, char **nb_list, int verbose)
{
    list_t *l_a = my_params_to_list(nb_int, nb_list);
    list_t *l_b = NULL;
    list_t *action_list = NULL;
    action_t actions = {&action_list, nb_int, 0, verbose, 0};

    if (nb_int > 1)
        insertion_sort(&l_a, &l_b, &actions);
    print_actions(&action_list);
    my_free_list(&l_b, 0);
    return (l_a);
}