/* This program gets the closest number to the input from fibunacci sequence
 * input: integer value
 * output: closest number
 * */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getFibonacciSet(int *fubunacciSet, int arraySize) {
    int first = 0;
    int second = 1;
    int next;

    for (int i = 0; i <= arraySize; i++) {
        next = first + second;
        first = second;
        second = next;
        fubunacciSet[i] = next;
    }
}

int getClosestNumberOf(int *fubunacciSet, int arraySize, int input) {

    int closestNumber = INT_MAX;
    for (int i = arraySize; i >= 0; i--) {
        if (abs(input - fubunacciSet[i]) > input) {
            closestNumber = fubunacciSet[i - 2];
        }
    }

    return closestNumber;
}

int main() {
    int arraySize = 25;
    int input;
    int *fubunacciSet = (int *) malloc(arraySize * (sizeof(int)));

    getFibonacciSet(fubunacciSet, arraySize);
    printf("enter number: ");
    scanf("%d", &input);

    if (input > 0) {
        int closestNumber = getClosestNumberOf(fubunacciSet, arraySize, input);
        printf("closest number from fibunacci sequence is: %d\n", closestNumber);
    } else if (input == 0) {
        printf("Error: Input larger number than 0\n");
    } else {
        printf("Error: Input positive number\n");
    }
    return 0;
}
