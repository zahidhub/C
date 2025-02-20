/*The elevator controller uses one byte (8 bits) to store the status of the elevator.

The values/meaning of the bits of the byte are:
Name           Bits       Info   
engine_on      1          Is engine on or off (the elevator moves or not). This is bit no 7 (MSB)
floor_pos      3          Which floor number the elevator should go to (0-7)  
door_pos       2          If the door is open or closed  
brake1         1          Normal brakes
brake2         1          Emergency brakes

We should store them in a byte like this:

[engine_on]  [floor_pos]   [door_pos]    [brake1]   [brake2]          
 1 bit       3 bits         2 bits        1 bit      1 bit
(8 bits in total)

Write a program which takes 5 arguments (different number of arguments should result in an error message).
The arguments should correspond to the values/variables above.
The program should also be able to print error message if the bit combination is invalid. 

Example for a start of the program from command line:

main   1 7 1 1 0

The above should be treated as:
Name                Value  
----------------------------
engine_on            1      
floor_pos            7
door_pos             1
brake1               1
brake2               0

and the output should be
0xF6*/

#include <stdio.h> // header file
#include <stdlib.h> // header file
#include <ctype.h> // header file

int main(int argc, char *argv[]) {

    if (argc != 6) { // check if there are 6 arguments
        printf("invalid number of arguments\n"); // print line for user
        return 0; // retun if not enuogh arguemtns
    }

    unsigned int engine_on = atoi(argv[1]); // assigning argument value to the variable
    unsigned int floor_pos = atoi(argv[2]); // assigning argument value to the variable
    unsigned int door_pos = atoi(argv[3]); // assigning argument value to the variable
    unsigned int brake1 = atoi(argv[4]); // assigning argument value to the variable
    unsigned int brake2 = atoi(argv[5]); // assigning argument value to the variable

    if (engine_on > 1) { // check if the the engine_on has valid value
        printf("invalid! engine_on must be 0 or 1.\n"); // print error for engine_on
        return 0; // return if invalid value
    }
    if (floor_pos > 7) { // check if the the floor_pos has valid value
        printf("invalid! floor_pos must be between 0 and 7.\n");  // print error for floor_pos
        return 0; // return if invalid value
    }
    if (door_pos > 2) { // check if the the door_pos has valid value
        printf("invalid! door_pos must be between 1 or 2.\n");  // print error for door_pos
        return 0; // return if invalid value
    }
    if (brake1 > 1) { // check if the the brake1 has valid value
        printf("invalid! brake1 must be 0 or 1.\n");  // print error for brake1
        return 0; // return if invalid value
    }
    if (brake2 > 1) { // check if the the brake2 has valid value
        printf("invalid! brake2 must be 0 or 1.\n");  // print error for brake2
        return 0; // return if invalid value
    }

    printf("engine_on: %d\n", engine_on); // print engine value
    printf("floor_pos: %d\n", floor_pos); // print floor value
    printf("door_pos: %d\n", door_pos); // print door position value
    printf("brake1: %d\n", brake1);  // print break1 value
    printf("brake2: %d\n", brake2);  // print break2 value

    unsigned int result = 0; // stroing values in an 8 bit ingerger

    /* here we are paacking all the input values into a single byte using bitwise operations
    each value is placed in its designated bit position using <<(left shift) and using bitwise |(OR)
    engine_on << 7: Moves engine_on (1 bit) to the leftmost position (bit 7)
    floor_pos << 4: Moves floor_pos (3 bits) to bits 6-4
    door_pos << 2: Moves door_pos (2 bits) to bits 3-2
    brake1 << 1: Moves brake1 (1 bit) to bit 1
    brake2: Stays in bit 0, no shift needed
    the bitwise | (OR) combines all these values into a single 8-bit number*/
    result = (engine_on << 7) | (floor_pos << 4) | (door_pos << 2) | (brake1 << 1) | brake2;

    char hex_digits[] = "0123456789ABCDEF";  // storing the hex character table
    char hex[3];  // vriable to store the hec value

    hex[0] = hex_digits[result / 16];  // getting the leftmost hex digit
    hex[1] = hex_digits[result % 16];  // getting the righmost hex digit
    hex[2] = '\0'; // add null-terminator to the hex value

    printf("0x%s\n", hex); // print the hex value

    return 0;
}