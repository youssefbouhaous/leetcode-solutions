class Solution {
public:
    int hIndex(vector<int>& c) {
        int l=0;
        int r=c.size()-1;
        int h=0;
        int n=c.size();
        while(l<=r){
            int m=(l+r)/2;
            if(c[m]>=n-m){
                h=max(h,min(c[m],n-m));
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return h;
    }
};