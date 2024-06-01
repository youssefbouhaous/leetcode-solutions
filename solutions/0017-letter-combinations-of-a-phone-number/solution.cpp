class Solution {
public:
    map<int,string>numToLetter;
    vector<string>ans;
    void f(int i,string a,string& b){
        if(a.size()==b.size() && a!=""){
            ans.push_back(a);
        }
        for(auto x:numToLetter[b[i]-'0']){
            a.push_back(x);
            f(i+1,a,b);
            a.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        numToLetter[2]="abc";
        numToLetter[3]="def";
        numToLetter[4]="ghi";
        numToLetter[5]="jkl";
        numToLetter[6]="mno";
        numToLetter[7]="pqrs";
        numToLetter[8]="tuv";
        numToLetter[9]="wxyz";
        string tmp="";
        f(0,tmp,digits);
        return ans;
    }
};