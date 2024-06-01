class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;
    void f(int i,int& target,int s,vector<int>& candidates){
        if(s==target){
            ans.push_back(tmp);
            return;
        }
        if(i>candidates.size()-1){
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(s+candidates[j]<=target){
                tmp.push_back(candidates[j]);
                f(j,target,s+candidates[j],candidates);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0,target,0,candidates);
        
        return ans;
    }
};