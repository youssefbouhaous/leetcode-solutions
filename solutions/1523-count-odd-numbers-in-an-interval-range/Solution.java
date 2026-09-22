class Solution {
    public int countOdds(int low, int high) {
        int c=0;
        if(high%2==1||low%2==1)c=1;
        return (high-low)/2+c;
    }
}