#include <stdio.H>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Printing numbers from 1 to %d:-\n", num);
    for(int i = 1; i <= num; i++) {
        printf("%d ", i);
    }
}