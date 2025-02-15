#include <stdio.h> // header file
#include <time.h> // header file
#include <stdlib.h> // header file

#define MAX 10 // defining the MAX number of random number we want to generate
#define MIN_RANGE 1 // defing the minimum value that can be generated in random
#define MAX_RANGE 99 // defing the minimum value that can be generated in random

/*The program generates random numbers and fills out the array, the array has a
size of MAX number and the random numbers are also generated within a range.
Later on, specific sections of the array is printed out*/
int main(int argc, char* argv[]){

    int array[MAX]; // variable to store MAX number of number
    srand(time(0)); // generate random number from time
    
    for(int i = 0; i < MAX ; i++){

        int randNum = (rand() % MAX_RANGE) + MIN_RANGE; // generating a random number and storing in the varibale
        array[i] = randNum; // storing the generated number in the array index
        printf("%d", array[i]); // printing the array filled with number
        printf(" "); // format for spacing
    }

    printf("\nThe value of the address of the array (pointer) is: %p\n", &array); // prints the memory address array
    printf("First integer in the array is (array[0]): %d\n", *array); // prints the first interger in the array
    printf("The last integer in the array is: %d\n", array[MAX-1]); // prints the last integer in the array
    printf("The size of an integer (number of bytes) is: %ld\n", sizeof(array)/sizeof(array[0])); // prints the size of a integer in the array
    printf("The size of the whole array in bytes is: %ld\n", sizeof(array)); // prints the size of the array

}