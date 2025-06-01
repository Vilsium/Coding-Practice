#include <stdio.h>

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int temp = num;
    int answer = 0;
    while(temp > 0) {
        int rem = temp % 10;
        answer += (rem*rem*rem);
        temp /= 10;
    }
    if(answer == num) printf("%d is an armstrong number", num);
    else printf("%d is not an armstrong number", num);
}