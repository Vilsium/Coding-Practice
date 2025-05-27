import java.util.Scanner;

public class PalindromeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number : ");
        int num = sc.nextInt();
        int temp = num;
        int result = 0;
        while(temp > 0) {
            result = result*10 + temp%10;
            temp /= 10;
        }
        if(result == num) System.out.print(num + " is a palindrome");
        else System.out.print(num + " is not a palindrome");
        sc.close();
    }
}
