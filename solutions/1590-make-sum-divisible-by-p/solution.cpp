class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=(total+nums[i])%p;
        }
        int tar=total%p;
        if(tar==0) return 0;
        unordered_map<int,int>mod;
        mod[0]=-1;
        int curs=0;
        int minl=n;
        for(int i=0;i<n;i++){
            curs=(nums[i]+curs)%p;
            int needed=(curs-tar+p)%p;
            if(mod.find(needed)!=mod.end()){
                minl=min(i-mod[needed],minl);
            }
            mod[curs]=i;
        }
        return minl==n ? -1:minl; 
    }
};