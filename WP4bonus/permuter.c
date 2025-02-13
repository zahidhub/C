#include <stdio.h> // header file
#include <string.h> // header file
#include <stdlib.h> // header file

void swapChar(char *char1, char *char2); // function signature for swaping character
void permutation(char *ch, int i, int endInd); // function signature for permutation


/*The main function holds condition for error handling, memory allocation
is created to store the generated permutation and then copied before freeing
the memeory and return 0 on success*/
int main(int argc, char *argv[]) {

    if (argc != 2) { // checks if there are 2 arguments
        printf("invalid"); // print line for inavlid argument
        return 0; // return on success
    } else if (strlen(argv[1]) > 10) { // checks of the provided argument is 10 character
        printf("invalid"); // print line for more than 10 character
        return 0; // return on success
    }

    
    char *word = malloc(strlen(argv[1]) + 1);  // memeory allocation for to store the character

    if (word == NULL) { // checks if memory allocation was failed
        printf("Memory allocation failed\n");
        return 0; // return on success
    }

    strcpy(word, argv[1]); // copy the word

    permutation(word, 0, strlen(word) - 1); // call the permutatuion function and give the word and its lenght as argument

    free(word); // free the memory
    word = NULL; // to prevent penetrating the memory again

    return 0; // return on success
}

/*This function is used to switch charaxter posiiton of two given charcater
it hold on of the character in a temporary variable and then the second character
is allocated to it*/
void swapChar(char *char1, char *char2) {
    char temp = *char1; // the variable stores the first character
    *char1 = *char2; // the first character stores the second character
    *char2 = temp; // the second character holds the temp varable(which is basically the first character)
}

/*This function is used for creating permutation of a string*/
void permutation(char *ch, int j, int endInd) {
    if (j == endInd) { // if the index matches the last index
        printf("%s\n", ch); // return the character on that given index
    } else {
        for (int i = j; i <= endInd; i++) { //
            swapChar(&ch[j], &ch[i]); // swaping charachter at position 
            permutation(ch, j + 1, endInd); // recusevly generate permutation for the leftout string
            swapChar(&ch[j], &ch[i]);  // swaping charachter at position 
        }
    }
}

// permutation logic inspired from - https://www.geeksforgeeks.org/c-program-to-print-all-permutations-of-a-given-string/