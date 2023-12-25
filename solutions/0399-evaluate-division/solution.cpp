class Solution {
public:
    map<string,vector<string>>m;
    map<pair<string,string>,double>w;
    map<string,bool>vi;
    set<string>exists;
    double ans=-1;
    void f(string v,double tmp=1,string p="",string ff=""){
        if(exists.count(v)==0){
            ans=-1;
            return ;
        }
        vi[v]=true;
        if( v==ff){
            ans=tmp;
            return;
        }
        for(auto x:m[v]){
            if(vi[x]!=true){
                f(x,tmp*w[{v,x}],v,ff);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            m[equations[i][0]].push_back(equations[i][1]);
            m[equations[i][1]].push_back(equations[i][0]);
            w[{equations[i][0],equations[i][1]}]=values[i];
            w[{equations[i][1],equations[i][0]}]=1/values[i];
            exists.insert(equations[i][0]);
            exists.insert(equations[i][1]);
        }
        vector<double>aa;
        for(auto x:queries){
            vi.clear();
            ans=-1;
            f(x[0],1,"",x[1]);
            aa.push_back(ans);
        }
        return aa;
    }
};