class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        queue<int>q;
        stack<int>st;
        
        for(auto x:po){
            q.push(x);
        }
        for(auto x:pu){
            st.push(x);
            if(st.top()==q.front()){
                while(!st.empty() && !q.empty() && q.front()==st.top()){
                    st.pop();
                    q.pop();
                }
            }
        }
        return q.empty();
    }
};