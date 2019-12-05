/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** test_swap_list.c
*/

#include <criterion/criterion.h>
#include "push_swap.h"

Test(swap_list, swap_the_two_first_element_of_a_list)
{
    list_t *list_a = my_list(2, 5, 4);
    list_t *list_b = my_list(2, -3, 12);
    list_t *action_list = NULL;
    action_t actions = {&action_list, 2, 0, 0, 0};

    swap_list_a(&list_a, &list_b, &actions);
    swap_list_b(&list_a, &list_b, &actions);
    swap_both(&list_a, &list_b, &actions);
    cr_expect_eq((int)list_a->data, 5);
    cr_expect_eq((int)(list_b->data), -3);
    my_free_list(&list_a, 0);
    my_free_list(&list_b, 0);
    my_free_list(&action_list, 0);
}

Test(push_to_list, put_the_first_element_of_a_list_into_an_another)
{
    list_t *list_a = my_list(2, 5, 4);
    list_t *list_b = my_list(2, -3, 12);
    list_t *action_list = NULL;
    action_t actions = {&action_list, 2, 0, 0, 0};

    push_to_list_b(&list_a, &list_b, &actions);
    push_to_list_a(&list_a, &list_b, &actions);
    cr_expect_eq((int)list_a->data, 5);
    cr_expect_eq((int)(list_b->data), -3);
    my_free_list(&list_a, 0);
    my_free_list(&list_b, 0);
    my_free_list(&action_list, 0);
}

Test(rotate_begin, put_the_first_element_as_the_last)
{
    list_t *list_a = my_list(2, 5, 4);
    list_t *list_b = my_list(2, -3, 12);
    list_t *action_list = NULL;
    action_t actions = {&action_list, 2, 0, 0, 0};

    rotate_begin_list_a(&list_a, &list_b, &actions);
    rotate_begin_list_b(&list_a, &list_b, &actions);
    rotate_begin_both(&list_a, &list_b, &actions);
    cr_expect_eq((int)list_a->data, 5);
    cr_expect_eq((int)(list_b->data), -3);
}

Test(rotate_end, put_the_last_element_as_the_first)
{
    list_t *list_a = my_list(2, 5, 4);
    list_t *list_b = my_list(2, -3, 12);
    list_t *action_list = NULL;
    action_t actions = {&action_list, 2, 0, 0, 0};

    rotate_end_list_a(&list_a, &list_b, &actions);
    rotate_end_list_b(&list_a, &list_b, &actions);
    rotate_end_both(&list_a, &list_b, &actions);
    cr_expect_eq((int)list_a->data, 5);
    cr_expect_eq((int)(list_b->data), -3);
}