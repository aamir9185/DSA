public class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        int traversalPtr = 0;
        int prev = Integer.MIN_VALUE;

        for (; traversalPtr < nums.length; traversalPtr++) {
            int currentElement = nums[traversalPtr];
            if (prev != currentElement) {
                nums[k] = currentElement;
                k++;
                prev = currentElement;
            }
        }


        return k;
    }
} 
