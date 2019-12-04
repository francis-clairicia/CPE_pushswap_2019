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
    char *numbers[] = {"2", "3", "1"};
    int nb_int = 3;
    list_t *sorted_list = NULL;
    list_t *node = NULL;

    cr_redirect_stdout();
    sorted_list = push_swap(nb_int, numbers, 0);
    node = sorted_list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&sorted_list, 0);
}

Test(push_swap, sort_a_list_with_a_single_number)
{
    char *numbers[] = {"12"};
    int nb_int = 1;
    list_t *sorted_list = NULL;
    list_t *node = NULL;

    cr_redirect_stdout();
    sorted_list = push_swap(nb_int, numbers, 0);
    node = sorted_list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&sorted_list, 0);
}

Test(push_swap, sort_a_list_of_positive_and_negative_numbers)
{
    char *numbers[] = {"2", "3", "1", "52", "12", "45", "32", "-23", "5",
        "-65", "-42", "2000", "2561352", "-362535", "-362534", "2561351",
        "20", "-21", "1", "0", "5", "4", "65", "32", "25351246897", "78",
        "-98", "-78", "-98", "-45", "45", "-65", "-89"};
    int nb_int = 33;
    list_t *sorted_list = NULL;
    list_t *node = NULL;

    cr_redirect_stdout();
    sorted_list = push_swap(nb_int, numbers, 1);
    node = sorted_list;
    while (node->next != NULL) {
        cr_expect_leq(node->data, node->next->data);
        node = node->next;
    }
    my_free_list(&sorted_list, 0);
}