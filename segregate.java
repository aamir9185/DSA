class Solution {

    public static void swap(int[] arr, int i, int j) {
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
 }

 void segregate0and1(int[] arr) {
     int l = 0, r = arr.length - 1;
     
     while (l < r) { 
         while (l < r && arr[l] == 0) l++; 
         while (l < r && arr[r] == 1) r--; 
         
         if (l < r) { 
             swap(arr, l, r);
             l++;
             r--;
         }
     }
 }
}