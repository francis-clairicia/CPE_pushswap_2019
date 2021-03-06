/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main.c
*/

#include "push_swap.h"

static int str_is_number(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '-' && my_find_char("0123456789", str[i]) < 0)
            return (0);
        i += 1;
    }
    return (1);
}

static int args_is_num(int ac, char **av)
{
    int i = 0;

    while (i < ac) {
        if (!str_is_number(av[i]))
            return (0);
        i += 1;
    }
    return (1);
}

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

int main(int ac, char **av)
{
    list_t *list;
    int verbose;
    int beginning;

    if (ac < 2)
        return (84);
    if (my_strcmp(av[1], "-v") == 0 && ac < 3)
        return (84);
    verbose = !my_strcmp(av[1], "-v");
    beginning = verbose + 1;
    if (!args_is_num(ac - beginning, &av[beginning]))
        return (84);
    list = my_params_to_list(ac - beginning, &av[beginning]);
    push_swap(&list, ac - beginning, verbose);
    my_free_list(&list, 0);
    return (0);
}