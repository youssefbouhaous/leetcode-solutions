class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        int count=1;
        int ans=1;
        int last=*st.begin();
        st.erase(st.begin());
        for(auto x:st){
            if(last+1==x){
                count++;
                last=x;
            }
            else{
                count=1;
                last=x;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};