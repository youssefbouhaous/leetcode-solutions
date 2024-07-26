class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pair<int,int>>p;
        set<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            p.push_back({max(abs(points[i][0]),abs(points[i][1])),i});
        }
        sort(p.begin(),p.end());
        int ans=0;
        //map<int,int>aa;
        for(int i=0;i<n;i++){
            if(st.count(s[p[i].second])){
                int tmp=0;
                for(auto x:p){
                    if(x.first!=p[i].first){
                        tmp++;
                    }
                    else{
                        break;
                    }
                }
                return tmp;
            }
            else{
                ans++;
                //aa[s[p[i].second]]=ans;
                st.insert(s[p[i].second]);
            }
        }
        return ans;
    }
};