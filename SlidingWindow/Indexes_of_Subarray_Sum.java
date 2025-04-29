import java.util.*;
/*
 * Problem:
Given an array of integers and a target sum, find the starting and ending indices of the first contiguous subarray that sums to the target. If no such subarray exists, return -1.
Consider 1-based indexing for the output.
*/
class Indexes_of_Subarray_Sum {

    static ArrayList<Integer> subarraySum(int[] arr, int target) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = 0;
        int n = arr.length;
        long sum = 0;
        while (j < n) {
            sum += arr[j];
            if (sum < target) {
                j++;
            } else if (sum == target) {
                ans.add(i + 1);
                ans.add(j + 1);
                return ans;
            } else {
                while (sum > target) {
                    sum -= arr[i];
                    i++;
                }
                if (sum == target) { //yaha dubara check karo agar sum target ke equal hai ya nahi
                    ans.add(i + 1);
                    ans.add(j + 1);
                    return ans;
                }
                j++;
            }
        }
        ans.add(-1);
        return ans;
    }

    public static void main(String[] args) {
        ArrayList<Integer> result = subarraySum(new int[]{1, 2, 3, 7, 5}, 12);
        if (result.size() == 2) {
            System.out.println("Subarray found from index " + result.get(0) + " to " + result.get(1));
        } else {
            System.out.println("No subarray found");
        }
    }
}
