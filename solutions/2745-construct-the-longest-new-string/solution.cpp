class Solution {
public:
    int longestString(int x, int y, int z) {
        int m=min(x,y);
        int ans= m*4+z*2;
        if(max(x,y)-m>0){ans+=2;}
        return ans;
    }
};