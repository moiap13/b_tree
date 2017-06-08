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

	pg->tab[1].t_state = OCCUPED;
	pg->tab[2].t_state = OCCUPED;
	pg->tab[3].t_state = OCCUPED;
	pg->tab[4].t_state = OCCUPED;

	pg->tab[1].value = 1;
	pg->tab[2].value = 2;
	pg->tab[3].value = 3;
	pg->tab[4].value = 8;


	for (int i = 1; i <= pg->order*2; i++)
	{
		printf("%d\n", pg->tab[i].value);

	}
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
	
	printf("%d\n", position(pg, 6));

	return 0;
}