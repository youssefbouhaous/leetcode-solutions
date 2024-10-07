class Solution {
public:
    int minLength(string s) {
        string q;
        for(auto x:s){
            if(!q.empty()){
                if(q.back()=='A' && x=='B'){
                    q.pop_back();
                }
                else if(q.back()=='C' && x=='D'){
                    q.pop_back();
                }
                else
                q.push_back(x);
            }
            else q.push_back(x);
        }
        return q.size();
    }
};