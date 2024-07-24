class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<int,int>d;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                cnt++;
                d[cnt]=i;
            }
        }
        vector<int>ans;
        for(auto y:queries){
            if(y>cnt){
                ans.push_back(-1);
            }
            else{
                ans.push_back(d[y]);
            }
        }
        return ans;
    }
};