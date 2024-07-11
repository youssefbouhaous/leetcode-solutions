class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' && !st.empty() && st.top().first=='('){
                auto t=st.top();
                st.pop();
                reverse(s.begin()+t.second,s.begin()+i);
                //cout<<s;
            }
            else if(s[i]==')' && !st.empty()){
                st.pop();
            }
            else if(s[i]=='('){
                st.push({s[i],i});
            }
        }
        string ans;
        for(auto x:s){
            if(x!='(' && x!=')'){
                ans.push_back(x);
            }
        }
        return ans;
    }
};