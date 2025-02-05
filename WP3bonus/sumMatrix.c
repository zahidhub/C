#include <stdio.h>

// this method clears buffer after user input
void clearBuffer (void) {
    char input;
    while ( (input = getchar()) != '\n' && input != EOF );
}

/*The program declares two integer varaiables to store the matrix dimension and later updates by the user inout
If the user enters invalid input the errors are handled in line 24. Next, the user is prompt to input values for
matrix one and two while checking if the values are valid, and the values and inserted in the matrix and prompt
to the user. Lastly, we sum the two matrix and show it to the user*/
int main(int argc, char * argv[]) {
    int row = 0; //variable to store row size
    int col = 0; //variable to store column size

    printf("Input the size: "); //asking user to enter the matrix size
    scanf("%d %d", &row, &col); //storing the user input values in row and col
    clearBuffer(); //clear buffer

    int matrix1[row][col]; //declaring a 2d array
    int matrix2[row][col]; //declaring second 2d array
    int sum[row][col]; //delaring the sum array

    // condition to check if the user input row and column size is valid
    if (row <=1 && col <= 1) { //if row and column size is 1 or less than 1
        printf("invalid\n"); //print invalid and exit the program
        return 0;
    }
    
    //####### TAKES INPUT FOR MATRIX 1 #######
    printf("Input elements of matrix 1: "); //prompt for user to enter the matrix1 values
    for (int i = 0; i < row; i++) { //looping through the matrix and inserting the values given by the user in the matrix(line 32)
        for (int j = 0; j < col; j++) {
            if(scanf("%d", &matrix1[i][j]) != 1){ // checkin if the user inputs are valid and has proper amount of values
                printf("invalid\n"); //return invalid if invalid values given
                return 0; // exits the program
                clearBuffer(); //clear buffer
            }
        }
    }
    
    //####### TAKES INPUT FOR MATRIX 2 #######
    printf("Input elements of matrix 2: "); //prompt for user to enter the matrix2 values
    for (int i = 0; i < row; i++) { //looping through the matrix and inserting the values given by the user in the matrix(line 44)
        for (int j = 0; j < col; j++) {
            if(scanf("%d", &matrix2[i][j]) != 1){ // checkin if the user inputs are valid and has proper amount of values
                printf("invalid\n"); //return invalid if invalid values given
                return 0; // exits the program
                clearBuffer(); //clear buffer
            }
        }
    }

    //####### PRINTS MATRIX 1 #######
    printf("Matrix 1: \n"); //printing prompt for matrix 1
    for (int i = 0; i < row; i++) { //looping through the matrix and getting the values in the matrix
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix1[i][j]); // printing matrix1 
        }
        printf("\n"); //print for formating
    }

    //####### PRINTS MATRIX 2 #######
    printf("Matrix 2: \n"); //printing prompt for matrix 1
    for (int i = 0; i < row; i++) {  //looping through the matrix and getting the values in the matrix
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix2[i][j]); // printing matrix2
        }
        printf("\n"); //print for formating
    }

    //####### SUM MATRIX 1 & 2 #######
    for (int i = 0; i < row; i++) { //looping through the matrix and getting the values in the matrix
        for (int j = 0; j < col; j++) {
        sum[i][j] =  matrix1[i][j] + matrix2[i][j]; //sum the two matrix (1&2)
        }
    }

    //####### PRINTS SUM OF MATRIX 1 & 2 #######
    printf("The sum is: \n"); //output line for sum
    for (int i = 0; i < row; i++) {  //looping through the matrix and getting the values in the matrix
        for (int j = 0; j < col; j++) {
            printf("%d ", sum[i][j]); //prints the sum of two matrices
        }
        printf("\n"); //print for formating
    }

    return 0; // return on successful execution

}