class Solution {
public:
    int d(string&a,string&b){
        int o=0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]){
                o++;
            }
        }
        return o;
    }
    int minMutation(string s, string e, vector<string>& b) {
        int ans=-1;
        queue<pair<string,int>>q;
        q.push({s,0});
        map<string,bool>v;
        v[s]=true;
        while(!q.empty()){
            string p=q.front().first;
            int l=q.front().second;
            v[p]=true;
            q.pop();
            if(p==e){
                return l;
            }
            for(auto x:b){
                if(!v[x] && d(p,x)==1){
                    v[x]=true;
                    q.push({x,l+1});
                }
            }
        }
        return -1;
    }
};