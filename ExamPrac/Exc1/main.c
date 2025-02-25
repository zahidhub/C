/*In this assignment, you must use the command line to provide the name of the person who is to be greeted. 

Example:

Command line: main.exe Miroslaw

Output: "Hello Miroslaw, how is your day today?"
Additional requirements:

If the program does not receive any name as the command line argument, it should output: "No command line argument provided, please provide a name. "
The name should be at most 50 characters - for longer names, the output should be "Name too long, max 50 characters"
The name should be at least 3 characters - for shorter names, the output should be "Name too short, min 3 characters"*/

#include <stdio.h> // header file
#include <string.h>

int main(int argc, char * argv[]){

    char *name = argv[1]; // the variable stores the argument

    if(argc != 2){ // checks if there are two arguments
        printf("No command line argument provided, please provide a name.");
        return 1;
    }

    int nameLength = strlen(name); // store the length of the argument

    if (nameLength > 50) // check if the name length is more than 50
    {
        printf("Name too long, max 50 characters\n");
        return 1;
    } else if (nameLength < 3) // check if the name lenght is less than 3
    {
        printf("Name too short, min 3 characters\n");
        return 1;
    }
    
    

    printf("Hello %s, how is your day today?\n", name); // print the name with message
    return 0; // return on Success

}