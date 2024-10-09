class Solution {
public:
    int minAddToMakeValid(string s) {
        string q;
        for(auto x:s){
            if(x=='('){
                q.push_back(x);
            }
            else{
                if(!q.empty() && q.back()=='(')q.pop_back();
                else q.push_back(x);
            }
        }
        return q.size();
    }
};