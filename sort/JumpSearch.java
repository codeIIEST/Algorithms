/* ===== ===== =====

Jump search
Developed by AadiCool

===== ===== ===== */

import java.util.*;

public class JumpSearch 
{

    public int jumpSearch(int[] arr, int val) 
    {
        int low = 0, high = arr.length - 1;

        while (high - low > 1)
        {
            Pair p = jumpSearchUtil(arr, val, low, high);

            if (p == null)
            {
                return -1;
            }

            low = p.left;
            high = p.right;
        }

        return arr[low] == val ? low : arr[high] == val ? high : -1;
    }

    private static Pair jumpSearchUtil(int[] arr, int val, int low, int high)
    {
        int left = low;
        int step = (int) Math.sqrt(high - low);
        int right = 0;

        while (left < high && arr[left] <= val)
        {
            right = Math.min(left + step, high);

            if (arr[left] <= val && arr[right] >= val)
            {
                return new Pair(left, right);
            }

            left = right;
        }

        return null;
    }

    public static void main(String[] args) 
    {
        System.out.println("Enter the array size");
        int n = new Scanner(System.in).nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter element no "+(i+1)+" ");
            arr[i]= new Scanner(System.in).nextInt();
        }
        System.out.println("Enter the element to be searched");
        int val = new Scanner(System.in).nextInt();
        int pos = new JumpSearch().jumpSearch(arr,val);
        if(pos==-1)
            System.out.println("Element not found");
        else
            System.out.println("Position of element is "+(pos+1));
    }
}

class Pair 
{
    int left, right;

    public Pair(int left, int right)
    {
        this.left = left;
        this.right = right;
    }
}