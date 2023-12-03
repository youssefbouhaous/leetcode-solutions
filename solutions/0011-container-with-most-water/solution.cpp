class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans=0;
        int l=0;
        int r=n-1;
        while(l<r){
            ans=max(ans,min(h[r],h[l])*(r-l));
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