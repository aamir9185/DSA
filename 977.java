

class Solution {
    public int[] sortedSquares(int[] nums) {
    int n = nums.length;
    int [] squares = new int [n]; 
    int left = 0;
    int right = n - 1;
    int index = n - 1;
    
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if(leftSquare > rightSquare){
            squares[index--] = leftSquare;
            left++;
        }
        else{
            squares[index --] = rightSquare;
            right--;
        }
    }

        return squares;
    }
}