/* This program calculates number from fibunacci sequence
 * input: integer value
 * output: number from the fibunacci sequence, corresponding to the input
 * */

#include <stdio.h>

int fibonacciNumber(int index){
    int first = 0, second = 1, next;

    for ( int i = 0 ; i <= index ; i++ )
    {
        if ( i <= 1 ){
            next = i;
        }

        else
        {
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}

int main() {
    int index, number;

    printf("Enter number from the fibunacci sequence: ");
    scanf("%d",&index);
    
    if(index > 0){
        number = fibonacciNumber(index);
        printf("number %d from the fibunacci sequence is: %d ",index,number);
    } else if(index == 0){
        printf("Error: Input larger number than 0\n");
    } else{
        printf("Error: Input positive number\n");
    }

    return 0;
}
