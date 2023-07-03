class Solution {
public:
    int maxArea(vector<int>& height) {
        int m=0;
        int lp=0;
        int rp=height.size()-1;
        while(lp<rp){
            m=max(m,(rp-lp)*min(height[lp],height[rp]));
            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return m;
    }
};