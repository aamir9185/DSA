class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m - 1; 
        int q = n - 1; 
        int i = m + n - 1; 

        while (p >= 0 && q >= 0) { 
            if (nums1[p] >= nums2[q]) {
                nums1[i] = nums1[p];
                p--;
            } else {
                nums1[i] = nums2[q];
                q--;
            }
            i--;
        }

        while (q >= 0) {
            nums1[i] = nums2[q];
            q--;
            i--;
        }
    }
}
