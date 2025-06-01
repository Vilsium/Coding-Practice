#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &num1, &num2);
    int minimumNumber;
    if(num1 <= num2) minimumNumber = num1;
    else minimumNumber = num2;
    int gcd = 1;
    for(int i = 2; i <= minimumNumber; i++) {
        if(num1 % i == 0 && num2 % i == 0) gcd = i;
    }
    printf("Greatest Common Divisor of %d and %d = %d", num1, num2, gcd);
}