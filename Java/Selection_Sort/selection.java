import java.lang.*;
import java.util.*;

class SelectionSort {

    Scanner s = new Scanner(System.in);

    void selection_Sort(int[] arr, int size) {
        int i, j, curr_min, temp;

        for (i = 0; i < size - 1; i++) {

            curr_min = i;

            for (j = i + 1; j < size; j++) {
                if (arr[j] < arr[curr_min]) {
                    curr_min = j;
                }
            }

            if (curr_min != i) {
                temp = arr[i];
                arr[i] = arr[curr_min];
                arr[curr_min] = temp;

            }
        }
    }

    void inputFromUser(int[] arr) {
        int i;
        int size = arr.length;
        System.out.println("Enter the Array Elements to be Sorted:\n");
        for (i = 0; i < size; i++) {
            arr[i] = s.nextInt();
        }

    }

    void printArray(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        SelectionSort item = new SelectionSort();
        int size;

        System.out.println("Enter the Size of Array:");
        size = item.s.nextInt();
        int[] arr = new int[size];

        item.inputFromUser(arr);

        item.selection_Sort(arr, size);
        item.printArray(arr);
    }
}