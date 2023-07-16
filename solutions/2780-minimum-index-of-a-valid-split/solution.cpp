class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>m;
        int cm;
        int ccm=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>ccm){
                cm=nums[i];
                ccm=m[nums[i]];
            }
        }
        vector<int>suf(n+1);
        for(int i=0;i<n;i++){
            if(nums[i]==cm){
                suf[i+1]=suf[i]+1;
            }
            else{
                suf[i+1]=suf[i];
            }
        }
        for(int i=0;i<n-1;i++){
            if(suf[i+1]*2>i+1 && (suf[n]-suf[i+1])*2>n-i-1){
                return i;
            }
        }
        return -1;
    }
};