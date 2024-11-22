struct comp {
    bool operator()(vector<int>& a, vector<int>& b) const
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),comp());
        set<int>a;
        set<int>b;
        a.insert(e[0][0]);
        b.insert(e[0][1]);
        int n=e.size();
        for(int i=1;i<n;i++){
            if(e[i][1]>(*(--b.end()))){
                b.insert(e[i][1]);
            }
            else{
                    auto it=b.lower_bound(e[i][1]);
                    if(it!=b.end()){
                        b.erase(it);
                        b.insert(e[i][1]);
                    }
                
            }
        }
        return b.size();
    }
};