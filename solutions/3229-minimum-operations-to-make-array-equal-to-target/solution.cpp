class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<long long int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(nums[i]-target[i]);
        }
        long long ans=abs(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]==0){
                continue;
            }
            else if(v[i]*v[i-1]>0){
                if(v[i]>0){
                    if(v[i-1]>v[i]){
                        continue;
                    }
                    else{
                        ans+=v[i]-v[i-1];
                    }
                }
                else{
                    if(v[i-1]<v[i]){
                        continue;
                    }
                    else{
                        ans+=v[i-1]-v[i];
                    }
                }
            }
            else{
                ans+=abs(v[i]);
            }
        }
        return ans;
    }
};