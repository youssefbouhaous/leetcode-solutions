class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            int tmp=0;
            while(l<=r){
                int mm=(l+r)/2;
                if((long long)potions[mm]*(long long)spells[i]>=success){
                    tmp=max(m-mm,tmp);
                    r=mm-1;
                }
                else{
                    l=mm+1;
                }
            }
            ans[i]=tmp;
        }
        return ans;
    }
};