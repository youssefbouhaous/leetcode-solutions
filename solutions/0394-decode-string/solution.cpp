class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto x:s){
            if(x!=']'){
                st.push(x);
            }
            else{
                string tmp;
                while(st.top()!='['){
                    tmp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string tmi;
                while(!st.empty() && '0' <= st.top() && st.top() <= '9'){
                    
                    tmi.push_back(st.top());
                    st.pop();
                }
                reverse(tmi.begin(),tmi.end());
                int v=stoi(tmi);
                reverse(tmp.begin(),tmp.end());
                while(v--){
                    for(auto u:tmp){
                        st.push(u);
                    }
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};