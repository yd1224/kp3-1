#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
double x, e;

double calculateRoot(double x, double k, double e);
double getInput(const char *prompt);
bool isScientificNotation(const char *input);

int main(void)
{
    printf("This program calculates the root of power of a number\n");
    int k;
   

    while (1)
    {
           x = getInput("Enter a number you want to get a root from: ");
           k = getInput("Enter the k-th root: ");
           


        if ((k > 0) && (k % 2 == 0) && (x < 0))
        {
            printf("\n");
            printf("If a root is even, x must be greater than or equal to 0. Please, try again. \n");
            printf("\n");
        }
        else if ((k < 0) && (k % 2 == 0) && (x <= 0))
        {
            printf("\n");
            printf("If a power is an even negative number, x must be greater than zero. Please, try again. \n");
            printf("\n");
        }
        else if ((k < 0) && (!(k % 2 == 0)) && (x == 0))
        {
            printf("\n");
            printf("If a power is an odd negative number, x must not be equal to zero. Please, try again. \n");
            printf("\n");
        }

        else if (k == 0)
        {
            printf("\n");
            printf("Power should not be equal to 0 or have a floating point. Please, try again.\n");
            printf("\n");
        }
        else if (k < 0)
        {
            k = abs(k);
            x = 1 / x;
            break;
        }
        else
        {
            break;
        }
    }

    while (1)
    {
       e = getInput("Enter precision: ");

        printf("\n");
        if (e < 1e-15)
        {
            printf("\n");
            printf("Precision must be between 1 and 1e-15. Please, try again\n");
            printf("\n");
        }
        else
        {
            break;
        }
    }

    calculateRoot(x, k, e);

    return 0;
}

double calculateRoot(double x, double k, double e)
{
    int i = 1;

    double delta = 1;
    double y = 1;


    if (x == 0 || x == 1)
    {
        switch ((int)x)
        {
        case 0:
            printf("y = 0\n");
            break;
        case 1:
            printf("y = 1\n");
            break;
        default:
            break;
        }
    }
    else
    {
        while (fabs(delta) >= e)
        {
            delta = 1.0 / k * (x / pow(y, k - 1) - y);
            y = y + delta;
            printf("\n");
            printf("\tdelta: %f\n", delta);
            printf("\ty = %f\n", y);
            i++;
        }
    }

    return y;
}


double getInput(const char *prompt) {
    char input[15];
    double number;

    do {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input) {
    int len = strlen(input);
    int eCount = 0;  
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'e' || c == 'E') {
            eCount++;
        } else if (isdigit(c) && eCount == 0) {
            digitsBeforeE++;
        } else if (isdigit(c) && eCount == 1) {
            digitsAfterE++;
        }
    }


    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}
