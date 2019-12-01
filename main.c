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

static void str_arr_to_int_arr(int ac, char **av, int *nb_list)
{
    int i = 0;

    while (i < ac) {
        nb_list[i] = my_getnbr(av[i]);
        i += 1;
    }
}

int main(int ac, char **av)
{
    int nb_list[ac];
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
    str_arr_to_int_arr(ac - beginning, &av[beginning], nb_list);
    push_swap(ac - beginning, nb_list, verbose);
    return (0);
}