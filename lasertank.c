/* FILE: lasertank.c
   AUTHOR: John Lumagbas
   ST-iD: 20165510
   UNIT: COMP1000 (UCP)
   PURPOSE: Create an ASCII lasertank puzzle game 
   LAST MOD: 18/04/2021 
   COMMENTS: Most of the criteria has been somewhate implemented except:
             - Changing laser color and a flowing animation.
             - Win situation implemented but no lose situation. 
             - Created a for loop to free, but 2nd and 3rd loops cause errors.
             - Laser must be shot closer to enemy to actually kill enemy. */

/* Libraries, and self-implemented files are called here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "inputCheck.h"
#include "newSleep.h"
#include "fieldMap.c"


/* Start of main() */
int main(int argc, char *argv[])
{
    
    /* Prototype declaration before first use */
    int fieldMap(int r, int c, int xPlayer, int yPlayer, char faceOf, int xEnemy, int yEnemy, char enemyFace);
    
    /* Parses int and char values in argv[] position */
    int r  = atoi(argv[1]);
    int c = atoi(argv[2]);
    int xPlayer = atoi(argv[3]);
    int yPlayer = atoi(argv[4]);
    char faceOf = *argv[5];
    int xEnemy = atoi(argv[6]);
    int yEnemy = atoi(argv[7]);
    char enemyFace = *argv[8];
    
    /* Check if array is within the 5 - 25 min/max range set by assignment */ 
    if(checkArr(r,c))
    {
    	printf("Invalid Array Size");
    	printf("\n");
    }
    else
    {
        /* If array is of valid size, game starts. */
        fieldMap(r, c, xPlayer, yPlayer, faceOf, xEnemy, yEnemy, enemyFace);
    }
    return 0;
}
    









