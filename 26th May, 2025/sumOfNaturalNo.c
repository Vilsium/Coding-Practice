#include <stdio.h>

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int sum = (num * (num+1))/2;
    printf("Sum of first %d natural numbers = %d", num, sum);
}