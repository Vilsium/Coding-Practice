import java.util.Scanner;

public class PrimeNumbersUttoN {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number till where you want to print the prime number : ");
        int num = sc.nextInt();
        System.out.println("Prime numbers till " + num + ":-");
        for(int i = 2; i <= num; i++) {
            if(isPrime(i)) System.out.print(i + " ");
        }
        sc.close();
    }

    public static boolean isPrime(int num) {
        for(int i = 2; i <= Math.sqrt((double)num); i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
}
