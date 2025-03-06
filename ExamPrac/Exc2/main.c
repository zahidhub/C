#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define BIT 8

int binNum8bit[BIT];
int counter = 0;
int onesCount = 0;
int zeroCount = 0;

void dec2bin(int deciNum){
     onesCount = 0;
 zeroCount = 0;

    while (deciNum > 0)
    {
        binNum8bit[counter] = deciNum % 2;
        deciNum = deciNum / 2;
        counter ++;
    }
    counter = 0;

    for(int i = BIT-1; i >= 0; i--){
        binNum8bit[i] = binNum8bit[i];
        printf("%d", binNum8bit[i]);
    }

    printf("\n");
    
}

void countZeroOne(int * binNum){
    int foundOne = 0;

    for (int i = 0; i < BIT; i++)
    {
        if (binNum[i] == 1)
        {
            onesCount++;
            foundOne = 1;
        } else if (foundOne)
        {
            zeroCount++;
            
        }
        
        
    }
}


int main (int argc, char * argv[]){
    char *decimalNum = argv[1];

    int convDeciNum = atoi(decimalNum);
    int * pConvDeciNum = &convDeciNum;


    if (argc != 2)
    {
        printf("Argument can not be empty!");
        return 1;
    } else if (!isdigit(*decimalNum))
    {
        printf("Argument should be a valid number");
        return 1;
    }

    dec2bin(*pConvDeciNum);

    


    countZeroOne(binNum8bit);

  
    printf("%d\n", onesCount);
    printf("%d\n", zeroCount);

}