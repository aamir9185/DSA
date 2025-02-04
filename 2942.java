// import java.util.ArrayList;
// import java.util.List;

// class Solution {
//     public List<Integer> findWordsContaining(String[] words, char x) {
//         List<Integer> result = new ArrayList<>();

//        for (int i = 0; i < words.length; i++) {
//         for (char letter : words[i].toCharArray()) {
//             if(letter == x){
//                 result.add(i);
//                 break;
//             }
//         }
//        }
 
//         return result;
//     }
// }
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            if (words[i].indexOf(x) != -1) {  // ✅ More efficient lookup
                result.add(i);
            }
        }
        return result;
    }
}
