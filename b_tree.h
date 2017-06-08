/**
 * @file b_tree.h
 * @brief binary tree
 *
 * header of a binary tree library
 *
 * @author Pisanello Antonio, antonio.pisanello@etu.hesge.ch
 * @bug No known bugs.
 * @date May 10th 2017
 * @version 0.1
*/

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Element
{
	int value;
	struct Page* pg;
} Element;

typedef struct Page
{
	int order;
	int nb_values;
	Element* tab;
} Page;

Page* new_page(int order);

#endif