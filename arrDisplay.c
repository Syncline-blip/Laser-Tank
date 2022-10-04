#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Simple function to display the array */

void mapDisplay(int r, int c, char ***field)
{
    int i,j;
    for(i=1; i <= r; i++)
    {
        for(j=1; j<= c; j++)
        {
            printf("%s", field[i][j]);
            if(i==1 || i==r || j==c || j==1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
