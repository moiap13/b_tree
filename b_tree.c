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
	for (int i = 1; i <= pg->order * 2; i++)
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

	pg->tab[2*pg->order+1].t_state = DISABLED;
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

	if (pg->tab[pos].t_state == OCCUPED) 
	{
		add_nb_value(pg);
		move(pg, pos);
		pg->tab[pos] = *cell;
	}

	if (pg->tab[pos].t_state == EMPTY)
	{	
		add_nb_value(pg);
		pg->tab[pos] = *cell;
		return 1;
	}

	if (pos == -1)
	{
		pg->tab[2*pg->order+1] = *cell;
		add_nb_value(pg);
	}

	if (pg->nb_values > 2*pg->order)
	{
		
		int i_element_up = pg->order+1;

		*cell = pg->tab[i_element_up];
		cell->pg = new_page(pg->order);

		for (int i = pg->nb_values - i_element_up; i > 0; i--)
		{
			cell->pg->tab[i] = pg->tab[i_element_up+i];
		}
		cell->pg->nb_values = pg->nb_values - i_element_up;

		Element* cell_null = malloc(sizeof(Element));
		cell_null->t_state = EMPTY;
		cell_null->pg = NULL;

		for (int i = i_element_up; i < pg->nb_values; ++i)
		{
			pg->tab[i] = *cell_null;
		}

		cell_null->t_state = DISABLED;
		pg->tab[pg->nb_values] = *cell_null;

		pg->nb_values = pg->order;
		return 1;
	}

	return 0;
}

Page* insert_cell(Page* b_tree, Element* cell, int depth)
{
	int pos = position(b_tree, cell->value);
	int i_return_place;

	if (b_tree->tab[pos-1].pg && pos != -1)
	{
		b_tree = insert_cell(b_tree->tab[pos-1].pg, cell, depth++);
	}
	else
	{
		i_return_place = place(b_tree, cell);
	}

	if (cell->pg)
	{
		if (depth == 0)
		{
			Page* pg = new_page(b_tree->order);
			pg->tab[0].pg = b_tree;
			place(pg, cell);
			return pg;
		}
		else
		{
			insert_cell(b_tree->tab[pos-1].pg, cell, depth--);
		}
	}

	return b_tree;
}

Page* insert(Page* b_tree, int key)
{
	Page* pg;
	Element* cell = malloc(sizeof(Element));

	if(cell == NULL)
	{
		printf("malloc element failed\n");
	}

	if(b_tree == NULL)
	{
		printf("Page null\n");
	}

	cell->t_state = OCCUPED;
	cell->value = key;

	pg = insert_cell(b_tree, cell, 0);

	//
	return pg;
}