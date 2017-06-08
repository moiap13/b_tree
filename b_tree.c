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
		if (pg->tab[i].value == key)
		{
			return -2;
		}

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

void move(Page* pg, int pos)
{
	for (int i = pg->nb_values; i >= pos; i--)
	{
		pg->tab[i + 1] = pg->tab[i];
	}
}

void add_nb_value(Page* pg)
{
	pg->nb_values++;
}

int place(Page* pg, Element* cell)
{
	int pos = position(pg, cell->value);

	if (pos == -2)
	{
		return 0;
	}

	if (pg->tab[pos].t_state == EMPTY)
	{
		pg->tab[pos] = *cell;

		return 1;
	}

	if (pg->nb_values == 2*pg->order)
	{
		move(pg, pos);
		add_nb_value(pg);

		cell = pg->tab[pg->order+1];
		cell->pg = new_page(2);

		for (int i = pg->nb_values - (pg->order + 1); i > 0; ++i)
		{
			cell->pg.tab[i] = pg->tab[order+1+i];
		}
	}
	else
	{
		move(pg, pos);
	}

	return 0;
}

Page* insert(Page* b_tree, int key)
{
	Page* pg;
	//
	return pg;
}