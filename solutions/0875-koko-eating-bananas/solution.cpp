class Solution {
public:
    bool possible(vector<int> piles, int h,int m){
        int i=0;
        int n=piles.size();
        while(h>0 && i<n){
            double a=m;
            double b=piles[i];
            h-=(int)(ceil(b/a));
            if(h<0){
                return false;
            }
            i++;
        }
        if(i==n){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l=1;
        int r=piles[piles.size()-1];
        int ans=piles[piles.size()-1];
        while(l<=r){
            int m=(l+r)/2;
            if(possible(piles,h,m)){
                r=m-1;
                ans=m;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};