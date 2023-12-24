class Solution {
public:

    set<set<int>>v;
    map<set<int>,bool>vi;
    int m;
    void f(set<int>st,int k,int i=0){
        if(i==k){
            if(st.size()==k){
                int ans=0;
                for(auto x:st){
                    ans+=x;
                }
                if(ans==m){
                    v.insert(st);
                }
            }
            return ;
        }
        for(int j=1;j<10;j++){
            if(st.count(j)==0){
                st.insert(j);
                if(vi[st]!=true){
                    vi[st]=true;
                    f(st,k,i+1);
                }
                st.erase(j);
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int>st;
        m=n;
        f(st,k);
        vector<vector<int>>ans;
        for(auto x:v){
            if(!x.empty()){
                vector<int>tmp;
                for(auto y:x){
                    tmp.push_back(y);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};