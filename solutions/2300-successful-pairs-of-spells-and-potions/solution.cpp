class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int mp=potions.size();
        for(int i=0;i<spells.size();i++){
            int r=potions.size()-1;
            int l=0;
            long long tmp=(long long)spells[i] *(long long) potions.back();
            int o=0;
            while(l<=r){
                int m=(l+r)/2;
                tmp=(long long)spells[i] *(long long) potions[m];
                if(success==tmp){
                    o=mp-m;
                    r=m-1;
                }
                else if(tmp<success){
                    l=m+1;
                }
                else{
                    o=mp-m;
                    r=m-1;
                }
            }
            ans.push_back(o);
        }
        return ans;
    }
};