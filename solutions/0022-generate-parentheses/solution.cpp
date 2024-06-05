class Solution {
public:
    vector<string>ans;
    void f(int i,int& n,string a){
        if(a.size()==2*n){
            if(i==0){
            ans.push_back(a);
            }
            return;
        }
        if(i<0){
            return;
        }
        a.push_back('(');
        f(i+1,n,a);
        a.pop_back();
        a.push_back(')');
        f(i-1,n,a);
    }
    vector<string> generateParenthesis(int n) {
        string tmp="";
        f(0,n,tmp);
        return ans;
    }
};