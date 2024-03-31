class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int l=0;
        int r=a.size()-1;
        int ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]==t){
                return m;
            }
            else if(a[m]<t){
                l=m+1;
                ans=l;
            }
            else{
                r=m-1;
                ans=r+1;
            }
        }
        return ans;
    }
};