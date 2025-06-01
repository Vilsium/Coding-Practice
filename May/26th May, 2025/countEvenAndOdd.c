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
    int evenCount = 0, oddCount = 0;
    for(int i = 0; i < sizeOfArray; i++) {
        if(arr[i] % 2 == 0) evenCount++;
        else oddCount++;
    }
    printf("No of even numbers in the array = %d\n", evenCount);
    printf("No of odd numbers in the array = %d", oddCount);
}