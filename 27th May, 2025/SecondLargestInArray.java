import java.util.Scanner;

class SecondLargestInArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of the array : ");
        int sizeOfArray = sc.nextInt();
        int[] arr = new int[sizeOfArray];
        System.out.println("Enter elements of array:-");
        for(int i = 0; i < sizeOfArray; i++) {
            int temp = sc.nextInt();
            arr[i] = temp;
        }
        int firstLargest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        for(int i : arr) {
            if(i > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = i;
            } else if(i > secondLargest && i != firstLargest) secondLargest = i;
        }
        System.out.println("Second largest element in the array = " + secondLargest);
        sc.close();
    }
}