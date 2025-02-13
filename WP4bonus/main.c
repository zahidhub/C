#include <stdio.h>
#include <string.h>

void swapChar(char * char1, char * char2);

int main(int argc, char * argv[]){
    if (argc !=2) {
        printf("Error! No argument found");
        return 0;
    } else if (strlen(argv[1]) > 10) {
        printf("Error! No argument found");
        return 0;
    }
    

    char * word = argv[1];
    char result[] = {0};

    printf("Enter your word: ");
    scanf("%s", word);

    for (int i= 0; i < strlen(word); i++){
        
    }
    
}

void swapChar(char * char1, char * char2){

    char temp;
    temp = * char1;
    * char1 = * char2;
    * char2 = * char1;

}

