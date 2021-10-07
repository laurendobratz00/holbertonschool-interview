#include "menger.h"
#include<math.h>

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return: 
 */

void menger(int level)
{
    int width, height, z = pow(3, level);

    if (level < 0)
    {
        ;
        exit(0);
    }
    if (level == 0)
    {
        printf("#\n");
        exit(0);
    }
    if (level >= 1)
    {
        for (width = 0; width < z; width++)
		{
			for (height = 0; height < z; height++)
			{
                if (width % 3 == 1 && height % 3 == 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}
