#define ll long long
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        int neg=0;
        int pos=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pos=0;
                neg=0;
            }
            else{
                if(nums[i]>0)pos++;
                else neg++;
                if(neg%2==0){
                    ans=max(ans,neg+pos);
                }
            }
        }
        pos=0;
        neg=0;
        for(int i=n-1;i>-1;i--){
            if(nums[i]==0){
                pos=0;
                neg=0;
            }
            else{
                if(nums[i]>0)pos++;
                else neg++;
                if(neg%2==0){
                    ans=max(ans,neg+pos);
                }
            }
        }
        return ans;
    }
};