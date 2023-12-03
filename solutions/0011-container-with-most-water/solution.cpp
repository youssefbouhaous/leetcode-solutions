class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans=min(h[0],h[n-1])*(n-1);
        int l=0;
        int r=n-1;
        while(l<r){
            if(h[l]<h[r]){
                l++;
            }
            else{
                r--;
            }
            ans=max(ans,min(h[r],h[l])*(r-l));
        }
        ans=max(ans,min(h[r],h[l])*(r-l));
        return ans;
    }
};