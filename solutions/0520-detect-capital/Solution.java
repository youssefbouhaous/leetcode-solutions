class Solution {
    public boolean detectCapitalUse(String word) {
        boolean upperAfterFirst = true;
        boolean lowerAfterFirst = true;
        for(int i=1;i<word.length();i++){
            upperAfterFirst = upperAfterFirst && Character.isUpperCase(word.charAt(i));
            lowerAfterFirst = lowerAfterFirst && (!Character.isUpperCase(word.charAt(i)));
        }
        if(Character.isUpperCase(word.charAt(0)) && (upperAfterFirst || lowerAfterFirst)) return true;
        if(!Character.isUpperCase(word.charAt(0)) && lowerAfterFirst) return true;
        return false;
    }
}
