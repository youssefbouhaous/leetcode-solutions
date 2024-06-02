class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       
        vector<string>ans;
        if(nums.size()==0){
            return ans;
        }
        int a=nums[0];
        int b=-1;
        bool f=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                if(!f){
                    ans.push_back(to_string(a));
                    a=nums[i];
                }
                else{
                    ans.push_back(to_string(a)+"->"+to_string(b));
                    a=nums[i];
                    f=false;
                }
            }
            else{
                f=true;
                b=nums[i];
            }
        }
        if(!f){
            ans.push_back(to_string(a));            
        }
        else{
            ans.push_back(to_string(a)+"->"+to_string(b));
        }
        return ans;
    }
};