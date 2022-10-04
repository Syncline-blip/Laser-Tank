#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "arrDisplay.c"
#include "colors.h"
#include "disp.c"
#include "newSleep.h"

#include "LinkedList.c"
/*toString method, converts variable into char/string*/
char* toString( void* var );

/* int fieldMap(): Creates and displays the array, takes in all the values from command line arguments */
int fieldMap(int r, int c, int xPlayer, int yPlayer, char faceOf, int xEnemy, int yEnemy, char enemyFace)
{
    
    int i, j, signal, signal2, winStatus, loseStatus;
    char ch, tank, tank2;
    linkedList* list = NULL;

    /* First dynamic allocation */
    char ***arrMap = malloc(r*c * sizeof(char*));
    char* inp = (char*)malloc(sizeof(char)*2);
    char* inp2 = (char*)malloc(sizeof(char)*2);
    char* inp3 = (char*)malloc(sizeof(char)*2);
    char* inp4 = (char*)malloc(sizeof(char)*2);
    char* inp5 = (char*)malloc(sizeof(char)*2);
    char* (*toStringPtr)( void* ) = &toString;
    strncpy(inp,"w",2);
    strncpy(inp2,"a",2);
    strncpy(inp3,"s",2);
    strncpy(inp4,"d",2);
    strncpy(inp5,"f",2);
    list = createLinkedList();
    
    
    for (i = 0; i<=r; i++)
    {
        for(j = 0; j<=c; j++)
        {
            /* Second dynamic allocation */
            arrMap[i] = malloc(r*c*sizeof(char*));   
        }  
    }
    /* NOTE: 2nd and 3rd allocations, r and c are iterated */
    for (i=0; i<= r; i++)
    {
        for(j = 0; j<=c; j++)
        {   
            /* Third dynamic allocation */
            arrMap[i][j] = malloc(r*c * sizeof(char));
            
            if(i!=1 || i!=r || j!=c || j!=1 || j != '>' || i != '>')
            {   
            	sprintf(arrMap[i][j], "%s", " ");
            }

            /* Switch cases for which direction a player and enemy should face
                depending on user input */
            switch(faceOf)
            {
            	case 'u':
            	    arrMap[xPlayer][yPlayer] = "^";
            	    signal = 1;
            	    break;
            	case 'd':
            	    arrMap[xPlayer][yPlayer] = "v"; 
            	    signal = 3;
            	    break;
            	case 'l':
            	    arrMap[xPlayer][yPlayer] = "<"; 
            	    signal = 2;
            	    break;
            	case 'r':
            	    arrMap[xPlayer][yPlayer] = ">";
            	    signal = 4; 
            	    break;
            }            
            switch(enemyFace)
            {
            	case 'u':
            	    arrMap[xEnemy][yEnemy] = "^";
                    signal2 = 1;
            	    break;
            	case 'd':
            	    arrMap[xEnemy][yEnemy] = "v";
                    signal2 = 3;
            	    break;
            	case 'l':
            	    arrMap[xEnemy][yEnemy] = "<";
                    signal2 = 2;
            	    break;
            	case 'r':
            	    arrMap[xEnemy][yEnemy] = ">";
                    signal2 = 4;
            	    break;
               
            }
        }
    }
    /* This will be repeated throughout the program, it clears
        then displays the arrary and interface */
    system("clear");
    mapDisplay(r,c,arrMap);
    interfaceDisplay();


    /* Cases to correct face and sets tank position, if the player is already in
        correct direction, it immediately moves the tank, else, it corrects it */
    while(ch != 'e')
    {
    	scanf("%c", &ch);
        if(ch == 'w')
        {	
            /* If the condition is true, it will insertLast the input of the user*/
            insertLast(list,inp);
            system("clear");
        	if((signal==1))
            {
        		arrMap[xPlayer][yPlayer] = " ";
        		xPlayer = xPlayer-1;
        		arrMap[xPlayer][yPlayer] = "^";
        		signal=0;			
        	}
        	else
        	{	
                arrMap[xPlayer][yPlayer] = " ";
                arrMap[xPlayer][yPlayer] = "^";             		
        	}
            /* If the signal is 3, and given that the y coords of enemy and player is the same
               then enemy will shoot*/
            if(signal2 == 3 && yPlayer == yEnemy)
            {

                tank2 = 'v';
                if(tank2 == 'v')
                {
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy+i][yEnemy]=(RED "|" reset);
                        mapDisplay(r,c,arrMap);
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy+i][yEnemy]=" ";      
                    } 
                    if(*arrMap[xPlayer][yPlayer] == ' ')
                    {
                        loseStatus = 1;
                    } 
                }
            } 
        	signal=1;
            tank = '^';
            mapDisplay(r,c,arrMap);
        	interfaceDisplay();
        }

        if(ch=='a')
        {
             
            insertLast(list,inp2);
            system("clear");
            if((signal ==2))
            { 
               
        	    arrMap[xPlayer][yPlayer] = " ";
        	    yPlayer = yPlayer-1;
        	    arrMap[xPlayer][yPlayer] = "<";
        	    signal=0;
	        }
	        else
	        {   
                
      		    arrMap[xPlayer][yPlayer] = " ";
        	    arrMap[xPlayer][yPlayer] = "<";  		
	        }
            /* If the signal is 4, and given that the y coords of enemy and player is the same
               then enemy will shoot*/
            if(signal2 == 4 && xPlayer == xEnemy)
            {
                tank2 = '>';
                if(tank2 == '>')
                {
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy][yEnemy+i]=(RED "—" reset);
                        mapDisplay(r,c,arrMap);
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy][yEnemy+i]=" ";      
                    } 
                    if(*arrMap[xPlayer][yPlayer] == ' ')
                    {
                        loseStatus = 1;
                    } 
                }
            }
	        signal=2;
            tank = '<';
	        mapDisplay(r,c,arrMap);
	        interfaceDisplay();
		
                
        }
        if(ch=='s')
        { 
            insertLast(list,inp3);
            system("clear");  
        	if((signal ==3))
        	{ 
        		arrMap[xPlayer][yPlayer] = " ";
        		xPlayer = xPlayer+1;
        		arrMap[xPlayer][yPlayer] = "v";
        		signal=0;
		    }
        	else
        	{ 
        		arrMap[xPlayer][yPlayer] = " ";
        		arrMap[xPlayer][yPlayer] = "v";
		    }
            /* If the signal is 1, and given that the y coords of enemy and player is the same
               then enemy will shoot*/
            if(signal2 == 1 && yPlayer == yEnemy)
            {
                tank2 = '^';
                if(tank2 == '^')
                {
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy-i][yEnemy]=(RED "|" reset);
                        mapDisplay(r,c,arrMap);
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy-i][yEnemy]=" ";      
                    } 
                    if(*arrMap[xPlayer][yPlayer] == ' ')
                    {
                        loseStatus = 1;
                    } 
                }
            }
		    signal=3;
            tank = 'v';
		    mapDisplay(r,c,arrMap);
            interfaceDisplay();
        }
        if(ch=='d') 
        {
            insertLast(list,inp4);
            system("clear"); 
        	if((signal ==4))
            {
                arrMap[xPlayer][yPlayer] = " ";
        		yPlayer = yPlayer+1;
        		arrMap[xPlayer][yPlayer] = ">";
            }
        	else
        	{ 
        		arrMap[xPlayer][yPlayer] = " ";
        		arrMap[xPlayer][yPlayer] = ">";	
		    }
            /* If the signal is 2, and given that the y coords of enemy and player is the same
               then enemy will shoot*/
            if(signal2 == 2 && xEnemy == xPlayer)
            {
                tank2 = '<';
        	    if(tank2 == '<')
                {
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy][yEnemy-i]=(RED "―" reset);
                        mapDisplay(r,c,arrMap);
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xEnemy][yEnemy-i]=" ";      
                    } 
                    if(*arrMap[xPlayer][yPlayer] == ' ')
                    {
                        loseStatus = 1;
                    }
                } 
            }
		    signal=4;
            tank = '>';
		    mapDisplay(r,c,arrMap);
            interfaceDisplay();
        }
        if(loseStatus ==1)
        {
                printf("-- You died! Game over! --");
                printf("\n");
                ch = 'e';
        }
        if(yPlayer == c || yPlayer == 1 || xPlayer == r || xPlayer == 0)
        {
            printf("Out of Bounds!");
            printf("\n-- OUT OF BOUNDS: MISSION FAILED --\n");
            ch='e';
        }
        
        /* Depending on the tank position, the laser is shot in the same direction */
        if(ch=='f')
        {   
            insertLast(list,inp5);
            system("clear");
            if((tank == '>' ))
            {       
                    /* Will animate a horizontal laser if the thank is facing right */
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer+i]=(RED "-" reset);
                        mapDisplay(r,c,arrMap);
                
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer+i]=" ";
                        mapDisplay(r,c,arrMap);
                        
                    }   
                    if(*arrMap[xEnemy][yEnemy] == ' ')
                    {
                        winStatus = 1;
                    }                    
            }
            if((tank == '<'))
            {
                /* Will animate a horizontal laser if the thank is facing left */
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer-i]=(RED "-" reset);
                        mapDisplay(r,c,arrMap);
           
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer-i]=" ";
                        mapDisplay(r,c,arrMap);
                    }
                    if(*arrMap[xEnemy][yEnemy] == ' ')
                    {
                        winStatus = 1;
                    }
            
            }
            if((tank == '^'))
            {
                /* Will animate a upwards laser if the thank is facing up */
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer-i][yPlayer]=(RED "|" reset);
                        mapDisplay(r,c,arrMap);
                 
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer-i][yPlayer]=" ";
                        mapDisplay(r,c,arrMap);
                   
                    }
                    if(*arrMap[xEnemy][yEnemy] == ' ')
                    {
                        winStatus = 1;
                    }
            }
            if((tank == 'v'))
            {
                /* Will animate a downwards laser if the thank is facing right */
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer+i][yPlayer]=(RED "|" reset);
                        mapDisplay(r,c,arrMap);
            
                    }
                    for(i=1;i<6;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer+i][yPlayer]=" ";
                        mapDisplay(r,c,arrMap);
                    
                    }
                    if(*arrMap[xEnemy][yEnemy] == ' ')
                    {
                        winStatus = 1;
                    }
            }
            
            if(winStatus ==1)
            {
                /* Once win, program exits */
                printf("WIN");
                printf("\n");
                ch = 'e';
            }
            interfaceDisplay();            
        }
               
    }
    /*Please see read me file*/
    /*for(i=0;i<=r;i++)
    {
        free(arrMap[i]);
        for(j=0;j<=c;j++)
        {
            free(arrMap[i][j]);
        }
    }*/

    /* FREE THE LINKED LIST, AND THE INPUTS */
    printLinkedList( list, &toStringPtr );
    free(inp);
    free(inp2);
    free(inp3);
    free(inp4);
    free(inp5);
    free(arrMap);   
    return 0;
}

char* toString( void* var )
{
    return (char*)var;
}
