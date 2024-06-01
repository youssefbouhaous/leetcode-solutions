class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;
    void f(int k,int p,vector<int>&d){
        if(tmp.size()==k){
            ans.push_back(tmp);
            return;
        }
        if( p>d.size()-1){
            return;
        }
        tmp.push_back(d[p]);
        f(k,p+1,d);
        tmp.pop_back();
        f(k,p+1,d);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmpv;
        for(int i=1;i<=n;i++){
            tmpv.push_back(i);
        }
        f(k,0,tmpv);
        return ans;
    }
};