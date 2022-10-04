/*FILE IO ATTMEPT: DOEST NOT WORK.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define r 10
#define c 128
int main()
{

    static char line[r][c];
    int i =0;
    FILE *f;
    int totalLines =0;
    f = fopen("map.txt", "r");
    if(f==NULL)
    {
        perror("ERROR IN PARSING");
    }
    while(fgets(line[i],c,f))
    {
        line[i][strlen(line[i])-1] = '\0';
        i++;
    }
    totalLines =i;
    for(i = 0; i < totalLines; ++i)
    {
        printf(" %s\n", line[1]);
    }
    return 0;
}