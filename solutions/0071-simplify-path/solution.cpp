class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int n=path.size();
        for(int i=0;i<n;i++){
            //cout<<ans<<" p:"<<path[i]<<endl;
            if(ans.empty()){ans.push_back(path[i]);}
            else if(path[i]=='/' && ans.back()=='/'){continue;}
            else if(ans.back()=='.' && path[i]=='.'){
                if(i<n-1 && path[i+1]!='/'){
                    ans.push_back(path[i]);
                }
                else if((int)ans.size()>1 && ans[(int)ans.size()-1]=='.' && ans[(int)ans.size()-2]!='/'){ans.push_back(path[i]);}
                else{
                    ans.pop_back();
                    if(!ans.empty())
                    ans.pop_back();
                    bool f=true;
                    //cout<<ans;
                    while(!ans.empty() && (ans.back()!='/') ){
                        ans.pop_back();
                    }
                }
            }
            else if(path[i]=='.' && ((i<n-1 && path[i+1]!='/')||(i>0 && path[i-1]!='/'))){
                ans.push_back(path[i]);
            }
            else if(path[i]=='.' && (i==n-1 || (path[i+1]!='.' && ans.back()!='.'))){continue;}
            
            else{
                ans.push_back(path[i]);
            }
        }
        string ss;
        for(auto x:ans){
            if(!ss.empty() && (x=='/' && ss.back()=='/')){
             continue;   
            }
            ss.push_back(x);
        }
        if(ss.empty()) return "/";
        if(ss!="/"){
            if(ss.back()=='/')ss.pop_back();
        }
        return ss;
    }
};