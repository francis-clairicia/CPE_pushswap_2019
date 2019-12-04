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

void push_swap(int nb_int, char **nb_list, int verbose)
{
    list_t *l_a = my_params_to_list(nb_int, nb_list);
    list_t *l_b = NULL;
    list_t *action_list = NULL;
    action_t actions = {nb_int, &action_list, verbose, 0};
    int str_size = 0;
    char *actions_to_print;

    if (nb_int > 1) {
        insertion_sort(&l_a, &l_b, &actions);
    } actions_to_print = my_concat_str_list(action_list, ' ', &str_size);
    write(1, actions_to_print, str_size);
    my_putchar('\n');
    my_free_list(&l_a, 0);
    my_free_list(&l_b, 0);
    my_free_list(&action_list, 0);
    free(actions_to_print);
}