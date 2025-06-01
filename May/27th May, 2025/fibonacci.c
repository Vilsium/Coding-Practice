#include <stdio.h>

int main() {
    int num;
    printf("Enter till which term you want to print fibonacci series: ");
    scanf("%d", &num);
    if(num == 1) {
        printf("%d", 0);
        return 0;
    } else if(num == 2) {
        printf("%d %d", 0, 1);
        return 0;
    }
    else {
        printf("%d %d", 0, 1);
        int a = 0, b = 1;
        for(int i = 2; i < num; i++) {
            int c = a+b;
            printf(" %d", c);
            a = b;
            b = c;
        }
    }
}