class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(x=='(' || x=='[' || x=='{'){
                st.push(x);
            }
            else if(!st.empty()){
                char t=st.top();
                st.pop();
                if(x==')' && t=='('){
                    continue;
                }
                else if(x==']' && t=='['){
                    continue;
                }
                else if(x=='}' && t=='{'){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};