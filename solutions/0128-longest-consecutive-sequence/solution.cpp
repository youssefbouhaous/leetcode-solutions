class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int c=1;
        int m=1;
        set<int>st(nums.begin(),nums.end());
        vector<int>nm(st.begin(),st.end());
        for(int i=0;i<nm.size()-1;i++){
            if(nm[i]+1==nm[i+1]){
                c++;
                m=max(m,c);
            }
            else{
                c=1;
            }
        }
        return m;
    }
};