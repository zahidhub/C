/*In this assignment, you must use the command line to provide the name of the person who is to be greeted. 

Example:

Command line: main.exe Hasan

Output: "Hello Miroslaw, how is your day today?"
Additional requirements:

If the program does not receive any name as the command line argument, it should output: "No command line argument provided, please provide a name. "
The name should be at most 50 characters - for longer names, the output should be "Name too long, max 50 characters"
The name should be at least 3 characters - for shorter names, the output should be "Name too short, min 3 characters"
*/

#include <stdio.h> //header file library
#include <string.h> //header file library

int main(int argc, char* argv[]) { // main function

    char* name = argv[1]; // name variable storing/pointing the index argument
    int arugmentCount = argc; // storing the number of argumnets

    // condition checkeing if the command line has any argument
    if (arugmentCount<2){

        // output if no arguments given
        printf("No command line argument provided, please provide a name.\n");
        
    } else {
        /*Checks if the argument provided has more than 50 charachter
        or if it has less than 3 character.
        If any of the above condition fullfills it returns output accordingly,
        otherwise it greets the argument.*/
        if (strlen(name) > 50 ) {
            printf("Name too long, max 50 characters\n");
            
        } else if (strlen(name)< 3) {
            printf("Name too short, min 3 characters\n");
            
        } else {
            printf("Hello %s, how is your day today?\n", name);
        }
    }
    return 0; // return on success
}