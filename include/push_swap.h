/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_swap.h
*/

#ifndef HEADER_PUSH_SWAP
#define HEADER_PUSH_SWAP

#include "my.h"
#include "mylist.h"

typedef struct action
{
    list_t **list;
    int verbose;
} action_t;

void push_swap(int nb_int, char **nb_list, int verbose);

void swap_list_a(list_t **l_a, list_t **actions);
void swap_list_b(list_t **l_b, list_t **actions);
void swap_both(list_t **l_a, list_t **l_b, list_t **actions);
int do_swap_a(list_t **l_a);
int do_swap_b(list_t **l_b);
int do_swap_both(list_t **l_a, list_t **l_b);

void push_to_list_a(list_t **l_a, list_t **l_b, list_t **actions);
void push_to_list_b(list_t **l_a, list_t **l_b, list_t **actions);

void rotate_begin_list_a(list_t **l_a, list_t **actions);
void rotate_begin_list_b(list_t **l_b, list_t **actions);
void rotate_begin_both(list_t **l_a, list_t **l_b, list_t **actions);

void rotate_end_list_a(list_t **l_a, list_t **actions);
void rotate_end_list_b(list_t **l_b, list_t **actions);
void rotate_end_both(list_t **l_a, list_t **l_b, list_t **actions);

void print_list(list_t *list);
void print_verbose(list_t **l_a, list_t **l_b, action_t *actions);

void insertion_sort(list_t **l_a, list_t **l_b, action_t *actions);

#endif