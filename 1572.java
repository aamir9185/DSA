class Solution {
    public int diagonalSum(int[][] mat) {
        
        int r = mat.length;
        int c = mat[0].length;

        int sum = 0;

        for (int i = 0; i < r ; i++) {
            int primaryDiagonal = mat[i][i];
            int secondary = c - i - 1;
            int secondaryColumn = mat[i][secondary];
             
             sum += primaryDiagonal;
            if (i != secondary){
                sum += secondaryColumn;
            }
        }

        return sum ;
    }
}
