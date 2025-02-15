#include <stdio.h>
#include <string.h>

#define MAX_CHAR 21

void copyString(char * str, char copiedString[]);

int main(int argc, char * argv[]){
    char string[MAX_CHAR];
    char copiedString[MAX_CHAR];

    printf("Enter your word: ");
    scanf("%s", string);

    printf("%ld \n", strlen(string));

    copyString(string, copiedString);

    printf("copied string %s \n", copiedString);


    return 0;
    

}

void copyString(char * str, char copiedString[]) {

    for (int i = 0; i <= strlen(str); i++) {

        if (strlen(str) == i)
        {
            copiedString[i] = '\0';
        } else {
            copiedString[i] = str[i];
        }
        
    } 
}