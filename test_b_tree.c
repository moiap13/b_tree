/**
 * @file b_tree.c
 * @brief binary tree
 *
 * use the binnary tree library
 *
 * @author Pisanello Antonio, antonio.pisanello@etu.hesge.ch
 * @bug No known bugs.
 * @date june 7th 2017
 * @version 0.1
*/

#include "b_tree.h"

int main(int argc, char** argv)
{

	Page* pg = new_page(2);

	pg = insert(pg, 2);
	pg = insert(pg, 3);
	pg = insert(pg, 4);
	pg = insert(pg, 1);
	pg = insert(pg, 5);
	pg = insert(pg, 6);
	pg = insert(pg, -1);
	pg = insert(pg, 7);
	pg = insert(pg, 8);
/*
	pg->tab[1].t_state = OCCUPED;
	pg->tab[2].t_state = OCCUPED;
	pg->tab[3].t_state = OCCUPED;
	pg->tab[4].t_state = OCCUPED;

	pg->tab[1].value = 1;
	pg->tab[2].value = 3;
	pg->tab[3].value = 8;
	pg->tab[4].value = 9;

	pg->nb_values = 4;
*/
	// for (int i = 1; i <= pg->order*2; i++)
	// {
	// 	printf("%d\n", pg->tab[i].value);
	// }
	// printf("/////\n");

	// Element* cell2 = malloc(sizeof(Element));
	// cell2->t_state = OCCUPED;
	// cell2->value = 2;

	// int hello = place(pg, cell2);
	
	// //Element* cell2 = malloc(sizeof(Element));
	// //cell2->t_state = OCCUPED;
	// cell2->value = 3;

	// hello = place(pg, cell2);	

	// //Element* cell2 = malloc(sizeof(Element));
	// //cell2->t_state = OCCUPED;
	// cell2->value = 1;

	// hello = place(pg, cell2);

	// cell2->value = 1;

	// hello = place(pg, cell2);

	// cell2->value = 4;

	// hello = place(pg, cell2);

	// cell2->value = 5;

	// hello = place(pg, cell2);
	// move(pg, 2);
	// pg->tab[2].value = 2;

	// for (int i = 0; i <= pg->order*2+1; i++)
	// {
	// 	printf("%d\n", pg->tab[i].value);
	// }
	/*for (int i = 0; i < pg->order*2+2; i++)
	{
		if (pg->tab[i].t_state == EMPTY)
		{
			printf("EMPTY\n");
		}
		else if (pg->tab[i].t_state == OCCUPED)
		{
			printf("OCCUPED\n");
		}
		else
		{
			printf("DISABLED\n");
		}
	}*/
	
	//printf("%d\n", position(pg, 3));

	return 0;
}
