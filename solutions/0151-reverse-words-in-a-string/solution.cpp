class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string tmp="";
        int c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(!tmp.empty())
                ans.push_back(tmp);
                tmp.clear();
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        if(!tmp.empty())
        ans.push_back(tmp);
        string sans;
        for(int i=ans.size()-1;i>0;i--){
            if(ans[i]!=" ")
            sans+=ans[i]+" ";
        }
        sans+=ans[0];
        return sans;
    }
};