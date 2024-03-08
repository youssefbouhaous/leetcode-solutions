class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int>v;
        int ans=0;
        set<pair<int,int>>st;
        map<int,int>d;
        for(int i=0;i<n;i++){
            st.insert({i,0});
        }
        for(int i=0;i<q.size();i++){
            pair<int,int>a={q[i][0],q[i][1]};
            auto it=st.find({q[i][0],d[q[i][0]]});
            auto b=it;
            b++;
            auto c=it;
            c--;
            if(it!=(--st.end())){
                if(it->second!=0 && b->second!=0 && it->second==b->second){
                    ans--;
                }
                if(q[i][1]==b->second){
                    ans++;
                }
            }
            if(it!=(st.begin())){
                if(it->second!=0 && c->second!=0 && it->second==c->second){
                    ans--;
                }
                if(q[i][1]==c->second){
                    ans++;
                }
            }
            d[q[i][0]]=q[i][1];
            v.push_back(ans);
            st.erase(it);
            st.insert(a);
        }
        return v;
    }
};