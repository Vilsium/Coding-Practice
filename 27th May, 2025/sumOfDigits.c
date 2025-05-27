#include <stdio.h>

int main() {
    int num;
    printf("Enter number : ");
    scanf("%d", &num);
    int temp = num;
    int result = 0;
    while(temp > 0) {
        result += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits of %d = %d", num, result);
}