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

void push_swap(int nb_int, int *nb_list, int verbose);

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

int list_sorted(list_t *list);
int list_reverse_sorted(list_t *list);
void print_list(list_t *list);

void bubble_sort(list_t **l_a, list_t **l_b, list_t **actions, int verbose);

#endif