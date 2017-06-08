/**
 * @file b_tree.c
 * @brief binary tree
 *
 * binary tree library
 *
 * @author Pisanello Antonio, antonio.pisanello@etu.hesge.ch
 * @bug No known bugs.
 * @date May 10th 2017
 * @version 0.1
*/

#include "b_tree.h"

Page* new_page(int order)
{
	Page *pg = NULL;

	pg = malloc(sizeof(Page));

	if (pg == NULL)
	{
		//printf(stderr, "malloc failed");
		exit(0);
	}

	pg->order = order;
	pg->nb_values = 0;
	pg->tab = malloc(sizeof(Element) * (2*order+2));

	if (pg->tab == NULL)
	{
		//printf(stderr, "malloc failed");
		exit(0);
	}

	for (int i = 0; i < 2*pg->order+2; i++)
	{
		pg->tab[i].t_state = EMPTY;
	}

	pg->tab[0].t_state = DISABLED;
	pg->tab[5].t_state = DISABLED;

	return pg;
}

int position(Page* pg, int key)
{
	for (int i = 1; i <= 2*pg->order; i++)
	{
		if (pg->tab[i].value > key)
		{
			return i;
		}

		if (pg->tab[i].t_state == EMPTY)
		{
			return i;
		}
	}

	return -1;
}

Page* insert(Page* b_tree, int key)
{
	Page* pg;
	//
	return pg;
}