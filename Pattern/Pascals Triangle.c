#include <stdio.h>

int main() 
{
    int rows;
    int coefficient = 1;
    
    printf("How many rows of Pascal's triangle?\n");
    scanf("%d", &rows);


    for (int i = 0; i < rows; i++) 
    {
        
        for (int j = 0; j < rows - i - 1; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++) {
            printf("%d ", coefficient);
            coefficient = coefficient * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}
