class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int a=0;
        int b=0;
        int n=nums.size();
        int ga=-1;
        int gb=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                a++;
                if(ga==-1){
                    ga=i;
                }
            }
            else{
                if(gb==-1){
                    gb=i;
                }
                b++;
            }
        }
        int ca=1;
        if(ga!=-1){
            int l=nums[ga]%2;
            for(int i=ga+1;i<n;i++){
                if(nums[i]%2!=l){
                    l=nums[i]%2;
                    ca++;
                }
            }
        }
        int cb=1;
        if(gb!=-1){
            int l=nums[gb]%2;
            for(int i=gb+1;i<n;i++){
                if(nums[i]%2!=l){
                    l=nums[i]%2;
                    cb++;
                }
            }
        }
        return max({cb,ca,a,b});
    }
};