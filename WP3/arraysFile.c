/*Write a program that reads in a string with a maximum of 20 characters from the keyboard and stores the string
in a local string variable.
Copy the string to another string by using:

a) The library function strcpy(..)
b) Your own function void copyString(...) not using any library function.

Main program ends by printing out the copied string in the console.
The program should be able to both read in from keyboard or from a text file ‘myfile.txt’ containing one string
of characters. You create this file with notepad or any other text editor. The reading from the text file should be
done by redirect the readings from command line when program execution starts as follows: Exerc_2_1 <
myfile.txt

Where Exerc_2_1 is the filename of the compiled program. You shall not use standard file managing by opening
the file and the read from it.*/

#include <stdio.h> // header file
#include <string.h> // header file

#define MAX_CHAR 21 // maximum character size

void copyString(char * str, char copiedString[]); // function prototype for copyString()

/*This program reads a text two different ways, from the keyboard and argument line.
When input given from the keyboard, the string is copied two different ways, with
the inbuilt method strcpy() and the manual method copyString(). Other than keyboard,
it gets a string from a txt file trough the command line*/
int main(int argc, char * argv[]){

    char string[MAX_CHAR]; // varibale to store the string
    char copiedString[MAX_CHAR]; // variable to store the copied string for inbuilt method
    char copiedString2[MAX_CHAR]; // variable to store the copied string for manual method

    FILE * textString = freopen(argv[1], "r", stdin); // reading the file given in the arguement line

    if (argc == 2) { // if there are two argument this condition gets executed
        fgets(string, MAX_CHAR, textString); // read the string from the txt file
    } else{
        printf("Enter your word: "); // print line for the user
        scanf("%s", string); // store the user input in the variable string
    }

    strcpy(copiedString, string); // call the inbuilt copy function
    copyString(string, copiedString2); // call the copyString function

    printf("Copied string (inbuilt method) %s \n", copiedString); // print line to print the inbuilt copied string
    printf("Copied string (manual method) %s \n", copiedString2); // print line to print the manual copied string
    
    return 0; // return on success
}

/*The method takes two parameter argument, one for the string and
one to store the copied variable.*/
void copyString(char * str, char copiedString[]) {

    for (int i = 0; i <= strlen(str); i++) { // itirates through the string till the last index
        
        if (strlen(str) == i) { // if last index, add the null terminator to the last string 
            copiedString[i] = '\0'; // ading the last null terminator in the last index
        } else {
            copiedString[i] = str[i]; // assigning str index values to copiedString
        }
    } 
}