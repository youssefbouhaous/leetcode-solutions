class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>xx;
        vector<pair<int,int>>yy;
        int sn=r.size();
        for(auto x:r){
            xx.push_back({x[0],x[2]});
            yy.push_back({x[1],x[3]});
        }
        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());
        int cnt=1;
        pair<int,int>cur=xx[0];
        for(int i=1;i<sn;i++){
            if(cur.second<=xx[i].first && cur!=xx[i]){
                cnt++;
                if(cnt>2)return true;
                cur=xx[i];
            }
            else{
                cur={cur.first,max(cur.second,xx[i].second)};
            }
        }
        if(cnt>2)return true;
        cnt=1;
        cur=yy[0];
        for(int i=1;i<sn;i++){
            if(cur.second<=yy[i].first && cur!=yy[i]){
                cnt++;
                if(cnt>2)return true;
                cur=yy[i];
            }
            else{
                cur={cur.first,max(cur.second,yy[i].second)};
            }
        }
        return  cnt>2;
    }
};