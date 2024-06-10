class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        long long int s=0;
        map<long long int,int>d;
        d[0]=1;
        for(int i=0;i<n;i++){
            s = (s + nums[i]) % k;
            if (s < 0) s += k;
            //cout<<st.count(k-s)<<";;"<<k-s<<" s:"<<s<<" ans"<<ans<<endl;
            if(d[s]){
                ans+=d[s];
            }
            d[s]++;
        }
        
        return ans;
    }
};