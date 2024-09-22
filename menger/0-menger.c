#include "menger.h"

/**
* menger - Function that draws a 2D Menger Sponge
*
* @level: the level of the Menger Sponge to draw
*/
void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int x = i, y = j;
			char print_char = '#';

			/* Check if this position is a hole or not */
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					print_char = ' ';  /* Its a hole, make it empty */
					break;
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", print_char);
		}
		printf("\n");
	}
}
