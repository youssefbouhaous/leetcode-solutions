class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        set<char>st;
        for(auto o:allowed){
            st.insert(o);
        }
        for(auto x:words){
            bool f=true;
            for(auto y:x){
                if(st.count(y)==0){
                    f=false;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};