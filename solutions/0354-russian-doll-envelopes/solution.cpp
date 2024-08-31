/*
Russian Doll Envelopes matriochka!!!!!
2D array
sorting by the first will give you the option that every e[i].first<=e[j].first tq i<j
but what is the problem is with the second
*/

class Solution {
    struct comp{
     bool operator() (vector<int>&a,vector<int>&b) const {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    };
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        set<int>st;
        set<int>b;
        sort(e.begin(),e.end(),comp());
        b.insert(e[0][0]);
        st.insert(e[0][1]);
        for(int i=1;i<e.size();i++){
            if(e[i][1]>(*(--st.end()))){
                st.insert(e[i][1]);
            }
            else{
                auto it=st.lower_bound(e[i][1]);
                if(it!=st.end()){
                    st.erase(it);
                    st.insert(e[i][1]);
                }
            }
        }
        return st.size();
    }
};