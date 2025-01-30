/*Write a program that counts the number of 0s and 1s in the binary representation of a decimal number. 

Your program should take a decimal number as argument. Then it should print the decimal number, it's binary representation and then count the number of 0s and 1s.

For example, for the following command:

main.exe 3
The output should be: 

Number: 3
Binary: 0b11
Number of 0s: 0
Number of 1s: 2
In this task, you must use bit operations. You are not allowed to convert the number to strings or arrays of any sort. Leading 0s should not be counted (e.g., 0b0011 should return "Number of 0s: 0; Number of 1s: 2"). 

Please remember that the program should handle errors:

When the argument is empty
When the argument is not a number (e.g., 0x11)*/

#include <stdio.h> // header files
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // This condition checks if arguments were provided
    // if not prints a message and exits the program
    if (argc != 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;
    }

    // variable declaration
    char *endptr;
    unsigned int number = strtoul(argv[1], &endptr, 10); // converting the string to an unsigned integer and storing it in number
    unsigned int bitCheker = 1 << 31; //bitCheker initialized to 32 bits
    int leadZero = 0; // to check for leading zeros in binary number
    int zeroCounter = 0; // to count the zeros
    int oneCounter = 0; // to count the ones

    // checks if the input is a valid number
    if (*endptr != '\0') {
        printf("Error: Invalid number.\n");
        return 0;
    }
    
    // prints the entered numbers and binanry format
    printf("Number: %u\n", number);
    printf("Binary: 0b");

    /* The loop keeps executing till the bitCheker is bigger than 0
    Then the if condition checks if the bit is 1 and prints out 1
    then it checks if  the current bit is 0 after the first 1
    which means its not a leading zero, so it gets printed
    lastly the 1 in bitCheker is shifted by one position
    */

    while (bitCheker > 0) {
        if (number & bitCheker) { // checks if the current bit is 1
            printf("1");
            leadZero = 1; // leadZero to 1 once we find the first 1
        } else if (leadZero) { // only print 0s after the first 1
            printf("0");
        }
        bitCheker >>= 1; // moves to the right bit
    }
    printf("\n");

    bitCheker = 1 << 31; // reset the bitCheker and fo through it again

    /* The loop keeps executing till the bitCheker is bigger than 0
    and counts the number of 1s and 0s
    The 0s are only counter after the first 1 is detected
    */
    while (bitCheker > 0) {
        if (number & bitCheker) { // if the current bit is 1
            oneCounter++;
        } else if (oneCounter > 0 || zeroCounter > 0) { // only count 0s after the first 1 is detected
            zeroCounter++;
        }
        bitCheker >>= 1; // moves to the right bit
    }

    // print the os and 1s in the binary number
    printf("Number of 0s: %d\n", zeroCounter);
    printf("Number of 1s: %d\n", oneCounter);

    return 0; // exit the program successfully
}