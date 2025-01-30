#include <stdio.h>
#include <unistd.h>

// enum for days of the days and week
enum Day { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun };
enum Week { Week1 = 1, Week2, Week3, Week4, Week5 };

//method clears buffer
void clearBuffer (void) {
    char input;
    while ( (input = getchar()) != '\n' && input != EOF );
}

// function to print the day name
// switch statement is used to check the inout day and print the appropiate day name
void printDay(enum Day day) {
    switch (day) {
        case Mon: 
            printf("Monday");
            break;
        case Tue: 
            printf("Tuesday");
            break;
        case Wed: 
            printf("Wednesday");
            break;
        case Thu: 
            printf("Thursday");
            break;
        case Fri: 
            printf("Friday"); 
            break;
        case Sat: 
            printf("Saturday");
            break;
        case Sun: 
            printf("Sunday");
            break;
    }
}

// function to print the week name
// switch statement is used to check the inout week and print the appropiate week
void printWeek(enum Week week) {
    switch (week) {
        case Week1:
            printf("Week 1");
            break;
        case Week2:
            printf("Week 2");
            break;
        case Week3:
            printf("Week 3");
            break;
        case Week4:
            printf("Week 4");
            break;
        case Week5:
            printf("Week 5");
            break;
    }
}

//main function
int main() {
    //variable declaration
    int weekInput;
    int dayInput;
    
    // ask the user for the week input
    printf("Provide starting week: ");
    scanf("%d", &weekInput);

    clearBuffer(); //clear buffer after storing the input
    
    // check if the weekinput is valid
    if (weekInput < 1 || weekInput > 5) {
        printf("invalid week\n");
        return 0;
    }
    
    // ask the user for the day input
    printf("Provide starting day: ");
    scanf("%d", &dayInput);
    
    // check if the weekinput in valid
    if (dayInput < 1 || dayInput > 7) {
        printf("invalid day\n");
        return 0;
    }
    
    // initializing the enums
    enum Week currentWeek = weekInput; // initialized with user input week
    enum Day currentDay = (enum Day)dayInput; // initialized with user input day
    
    /*The loop continues till the week is 5 and the day is sunday
    in each loop it prints the current week and currentday and sleeps for 1 second
    Then it incriments the days, when its sunday it resets the day to monday and moves to the next week
    and if not sunday it keeps incrimenting the day.
    and it finally stops whem the loop reaches week5 and sunday
    */
    while (currentWeek <= Week5) {

        //prints the current week and currentday and sleeps for 1 second
        printWeek(currentWeek);
        printf(", ");
        printDay(currentDay);
        printf("\n");
        sleep(1);
        
        // increment day and possibly the week
        if (currentDay == Sun) { // when its sunday it resets the day to monday
            currentDay = Mon;
            currentWeek++;
        } else {
            currentDay = (enum Day)(currentDay + 1);
        }
        
        // stops the loop if we reach Week 5 and Sunday
        if (currentWeek == Week5 && currentDay == Sun) {
            printWeek(currentWeek);
            printf(", ");
            printDay(currentDay);
            printf("\n");
            break;
        }
    }

    return 0;
}