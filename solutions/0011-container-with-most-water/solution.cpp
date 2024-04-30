class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int l=0;
        int r=h.size()-1;
        while(l<r){
            ans=max(ans,(r-l)*min(h[l],h[r]));
            if(h[l]<h[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};