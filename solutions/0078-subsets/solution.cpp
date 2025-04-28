class Solution {
public:
    vector<vector<int>>ans;
    vector<int>s;
    void f(vector<int>&v,int i){
        if(i>=v.size()){
            ans.push_back(s);
            return;
        }
        s.push_back(v[i]);
        f(v,i+1);
        s.pop_back();
        f(v,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums,0);
        return ans;
    }
};