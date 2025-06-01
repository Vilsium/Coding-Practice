import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class frequencyOfElements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array : ");
        int sizeOfArray = sc.nextInt();
        int[] arr = new int[sizeOfArray];
        System.out.println("Enter elemts of array:-");
        for(int i = 0; i < sizeOfArray; i++) {
            int temp = sc.nextInt();
            arr[i] = temp;
        }
        HashMap<Integer, Integer> mpp = new HashMap<>();
        for(int i : arr) {
            mpp.put(i, mpp.getOrDefault(i, 0)+1);
        }
        System.out.println("Frequency of elements of array:-");
        for(Map.Entry<Integer, Integer> entry : mpp.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
        sc.close();
    }
}
