
/* lsShoot (please see comment above */ 

#include "ANSI-color-codes.h"
#include "laser.h"
#include "newSleep.h"
void lsShoot(int xPlayer, int yPlayer, int r, int c, char tank, char ***arrMap)
{

    int i;
    for(r=0;r<xPlayer;r++)
    {
        for(c=0;c<yPlayer;c++)
        {   
            
            if((tank == '>'))
            {
                    system("clear");
                    newSleep(0.00005);
                    for(i=1;i<7;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer+i]=(RED "—" reset);
                        
                    }
            }
            else if((tank == '<'))
            {
                
                for(i=1;i<6;i++)
                {
                   arrMap[xPlayer][yPlayer- i]=(RED "-" reset);
                }
            }
            else if((tank == '^'))
            {

                
                system("clear");
                    newSleep(0.00005);
                    for(i=1;i<7;i++)
                    {   
                        newSleep(0.05);
                        system("clear");
                        arrMap[xPlayer][yPlayer+i]=(RED "—" reset);
                        
                    }
            }
            else if((tank == 'v'))
            {
                for(i=1;i<6;i++)
                {
                   arrMap[xPlayer+i][yPlayer]=(RED "|" reset);
                } 
            }
        }
    }
    
}

/* lsRemove (please see comment above) */
void lsRemove(int xPlayer, int yPlayer, int r, int c, char tank, char ***arrMap)
{
    int i;
    for(c=0;c<yPlayer;c++)
    {
        for(r=0;r<xPlayer;r++)
        {
            if((tank == '>'))
            {
                for(i=1;i<6;i++)
                {
                    arrMap[xPlayer][yPlayer+i]=" ";
                }
            }
            else if((tank=='<'))
            {
                for(i=1;i<6;i++)
                {
                    arrMap[xPlayer][yPlayer-i]=" ";
                }
            }
            else if((tank == '^'))
            {
                for(i=1;i<6;i++)
                {
                   arrMap[xPlayer-i][yPlayer]=" ";
                }
            }
            else if((tank == 'v'))
            {

                for(i=1;i<6;i++)
                {
                   arrMap[xPlayer+i][yPlayer]=" ";
                }
            }
        }
    }
    
}