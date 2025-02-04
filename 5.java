
class Solution {
    public boolean isPalindrome(String s){
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if(s.charAt(i) != s.charAt(j))
            return false;

            i ++;
            j --;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        int len = s.length();
        String longestPalindrome = "";
        for (int i = 0; i < len; i++) {
            String subString = "";
            for (int j = i; j < len; j++) {
                subString += (s.charAt(i) + "");
                if(isPalindrome(subString) && subString.length() > longestPalindrome.length()){
                    longestPalindrome = subString;
                }
            }
            
        }
        return longestPalindrome;
    }
}