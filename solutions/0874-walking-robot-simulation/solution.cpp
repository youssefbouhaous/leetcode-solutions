class Solution {
public:
    int robotSim(vector<int>& cms, vector<vector<int>>& ob) {
        set<pair<int,int>>st;
        for(auto x:ob){
            st.insert({x[0],x[1]});
        }
        pair<int,int>cur={0,0};
        int d=0;
        pair<int,int>s={0,1};
        bool f=false;
        int ans=0;
        for(auto y:cms){
            if(y==-1){
                d++;
                d=d%4;
                if(d==0){
                    s={0,1};
                }
                if(d==1){
                    s={1,0};
                }
                if(d==2){
                    s={0,-1};
                }
                if(d==3){
                    s={-1,0};
                }
            }
            else if(y==-2){
                d--;
                d=d%4;
                if(d<0){
                    d+=4;
                }
                if(d==0){
                    s={0,1};
                }
                if(d==1){
                    s={1,0};
                }
                if(d==2){
                    s={0,-1};
                }
                if(d==3){
                    s={-1,0};
                }
            }
            else{
            while(y--){
            if(st.count({cur.first+s.first,cur.second+s.second})){
                break;
            }
            else{
                cur={cur.first+s.first,cur.second+s.second};
                ans=max(ans,cur.first*cur.first+cur.second*cur.second);
            }
            }
            }
        }
        return ans;
    }
};