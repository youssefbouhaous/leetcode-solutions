class Solution {
public:
    map<int,bool>vi;
    bool dfs(int i,vector<int>&a){
        if(a[i]==0){
            return true;
        }
        if(i+a[i]<a.size() && vi[i+a[i]]!=true){
            vi[i+a[i]]=true;
            if(dfs(i+a[i],a)){
                return true;
            }
        }
        if(i-a[i]>=0 && vi[i-a[i]]!=true){
            vi[i-a[i]]=true;
            if(dfs(i-a[i],a)){
                return true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(start,arr);
    }
};