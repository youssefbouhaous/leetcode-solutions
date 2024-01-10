class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n,-1);
        int m=*max_element(nums.begin(),nums.end());
        for(int i=0;i<2*n;i++){
            if(nums[i%n]==m){
                continue;
            }
            else if(nums[i%n]<nums[(i+1)%n]){
                ans[i%n]=nums[(i+1)%n];
                int mm=st.size();
                while(mm--){
                    if(nums[st.top()]<ans[i%n]){
                    ans[st.top()]=ans[i%n];
                    st.pop();
                    }
                }
            }
            else{
                st.push(i%n);
            }
        }
        return ans;
    }
};