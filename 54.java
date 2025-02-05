import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int rows = matrix.length;
        int cols = matrix[0].length;

        int up = 0;
        int down = rows -1;
        int left = 0;
        int right = cols -1;
        int totalElements = rows * cols ;

        int count = 0 ; 
        while (count < totalElements) {

            //left to right
             for (int col = left; col <= right && count < totalElements;col++) {
                result.add(matrix[up][col]);
                count ++;
             }
            //top to bottom
            for (int row = up + 1; row <= down && count < totalElements; row++) {
                result.add(matrix[row][right]);
                count ++;
            }
            //right to left
            for (int col = right - 1; col >= left && count < totalElements; col--) {
                result.add(matrix[down][col]);
                count ++;
            }

            //bottom to up
            for (int row = down -1; row >  up && count < totalElements; row--) {
                result.add(matrix[row][left]);
                count ++;
            }
            up ++;
            down --;
            right --;
            left ++;

        }

        return result;
    }
}
