class Solution {
public:
    map<char,string>m;
    vector<string>ans;
    void f(string d,string tmp,int i=0){
        if(i==d.size()){
            if(tmp!="")
            ans.push_back(tmp);
            return ;
        }
        for(auto x:m[d[i]]){
            tmp.push_back(x);
            f(d,tmp,i+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {    
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        f(d,"");
        return ans;
    }
};