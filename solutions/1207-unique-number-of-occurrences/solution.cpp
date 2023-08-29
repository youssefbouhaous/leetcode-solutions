class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>d;
        set<int>p;
        for(auto x:arr){
            d[x]++;
            p.insert(x);
        }
        set<int>st;
        for(auto x:p){
            if(st.count(d[x])>0){
                return false;
            }
            st.insert(d[x]);
        }
        return true;
    }
};