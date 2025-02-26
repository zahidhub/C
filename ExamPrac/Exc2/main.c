#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BIT_8 8

int binNum8bit[BIT_8];
int counter = 0;

void dec2bin(int deciNum){

    while (deciNum > 0)
    {
        binNum8bit[counter] = deciNum % 2;
        deciNum = deciNum / 2;
        counter ++;
    }
    
}


int main (int argc, char * argv[]){
    char *decimalNum = argv[1];

    int convDeciNum = atoi(decimalNum);
    int * pConvDeciNum = &convDeciNum;

    int revBinNum8bit[BIT_8];

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

    for(int i = BIT_8-1; i >= 0; i--){
        revBinNum8bit[i] = binNum8bit[i];
        printf("%d", revBinNum8bit[i]);
    }



}