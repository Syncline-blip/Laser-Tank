#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#endif
/* checks if the array size is valid, if its greater than 25 and lower than 5 vice versa for rows and cols
    then the input is invalid */

#define checkArr(rowSize, colSize) (((rowSize) > (25)) || ((rowSize) < (5)) || ((colSize) > (25)) || ((colSize) < (5)) ? 1:0)



