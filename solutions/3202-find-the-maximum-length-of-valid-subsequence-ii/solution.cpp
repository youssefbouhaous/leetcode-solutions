class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<3){
            return n;
        }
        int ans=1;
        set<int>pos;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%k;
            pos.insert(nums[i]%k);
        }
        unordered_map<int,bool>v;
        for(int i=0;i<n;i++){
            if(v[nums[i]%k]){
                continue;
            }
            v[nums[i]%k]=true;
            int c=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]%k==nums[i]%k)
                    c++;
            }
            int cc=1;
            pos.erase(nums[i]%k);
            for(auto x:pos){
                int tcc=1;
                bool f=false;
                for(int j=i+1;j<n;j++){
                    if(!f && nums[j]==x){
                        tcc++;
                        f=!f;
                    }
                    else if(f && nums[j]==nums[i]){
                        tcc++;
                        f=!f;
                    }
                }
                cc=max(cc,tcc);
            }
            ans=max({cc,ans,c});
        }
        return ans;
    }
};