#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int num;
    printf("Enter any number: ");
    scanf("%d", &num);
    bool isPrime = true;
    if(num <= 1) isPrime = false;
    else {
        for(int i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if(isPrime) printf("%d is a prime number", num);
    else printf("%d is not a prime number", num);
}