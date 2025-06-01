#include <stdio.h>

int main() {
    int num;
    printf("Enter number : ");
    scanf("%d", &num);
    int temp = num;
    int result = 0;
    while(temp > 0) {
        result = result*10 + temp%10;
        temp /= 10;
    }
    printf("Reverse of %d = %d", num, result);
}