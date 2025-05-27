#include <stdio.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int fact = 1;
    for(int i = num; i > 0; i--) {
        fact *= i;
    }
    printf("%d! = %d", num, fact);
}