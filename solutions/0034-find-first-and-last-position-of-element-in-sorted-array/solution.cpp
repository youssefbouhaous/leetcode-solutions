class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        vector<int>v={-1,-1};
        int l=0;
        int r=a.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]==t){
                v[0]=m;
                r=m-1;
            }
            else if(a[m]>t){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=0;
        r=a.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]==t){
                v[1]=m;
                l=m+1;
            }
            else if(a[m]>t){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return v;
    }
};