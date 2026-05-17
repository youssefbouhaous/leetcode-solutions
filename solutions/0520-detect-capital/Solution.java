class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        return word.equals(word.toUpperCase()) || word.equals(word.toLowerCase())
                || word.equals(word.substring(0,1).toUpperCase()+word.substring(1,n).toLowerCase());
    }
}
