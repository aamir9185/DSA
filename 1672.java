class Solution {
    public int maximumWealth(int[][] accounts) {
        int MaximunWealth = 0;
        for(int [] account : accounts){
            int sum = 0;
            for (int wealth : account){
                sum += wealth ;
            }
            MaximunWealth = Math.max(MaximunWealth, sum);
        }
        return MaximunWealth;
    }
}