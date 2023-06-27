class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        set<pair<int,int>>st;
        for(auto x:pairs){
            st.insert({x[1],x[0]});
        }
        int c=1;
        int p=st.begin()->first;
        for(auto x:st){
            if(x.second>p){
                c++;
                p=x.first;
            }
        }
        return c;
    }
};