/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** test_push_swap.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "push_swap.h"

Test(push_swap, sort_a_list_of_simple_numbers)
{
    int nb_int = 9;
    list_t *list = my_list(nb_int, 2, 1, 6, 3, 5, 1, 8, 7, 4);
    list_t *node = NULL;

    cr_redirect_stdout();
    push_swap(&list, nb_int, 0);
    node = list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&list, 0);
}

Test(push_swap, sort_a_list_with_a_single_number)
{
    int nb_int = 1;
    list_t *list = my_list(nb_int, 12);
    list_t *node = NULL;

    cr_redirect_stdout();
    push_swap(&list, nb_int, 0);
    node = list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&list, 0);
}

Test(push_swap, sort_a_list_of_positive_and_negative_numbers)
{
    int nb_int = 33;
    list_t *list = my_list(nb_int, 2, 3, 1, 52, 12, 45, 32, -23, 5, -65,
        -42, 2000, 2561352, -362535, -362534, 2561351, 20, -21, 1, 0, 5, 4,
        65, 32, 25351246897, 78, -98, -78, -98, -45, -65, -89);
    list_t *node = NULL;

    cr_redirect_stdout();
    push_swap(&list, nb_int, 0);
    node = list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&list, 0);
}