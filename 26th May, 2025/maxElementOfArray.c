#include <stdio.h>

int main() {
    int sizeOfArray;
    printf("Enter size of array: ");
    scanf("%d", &sizeOfArray);
    int arr[sizeOfArray];
    printf("Enter array elements:-\n");
    for(int i = 0; i < sizeOfArray; i++) {
        scanf("%d", &arr[i]);
    }
    int maxElement = arr[0];
    for(int i = 1; i < sizeOfArray; i++) {
        if(arr[i] > maxElement) maxElement = arr[i];
    }
    printf("Maximum element of the array = %d", maxElement);
}