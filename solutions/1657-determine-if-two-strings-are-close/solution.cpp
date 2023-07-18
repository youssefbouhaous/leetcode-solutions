class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        map<char,int>m1;
        map<char,int>m2;
        map<char,bool>u;
        map<char,bool>u2;
        for(auto x:word1){
            m1[x]++;
        }
        for(auto x:word2){
            m2[x]++;
        }
        multiset<int>st;
        for(auto x:word2){
            if(u[x]==1){
                continue;
            }
            u[x]=1;
            st.insert(m2[x]);
        }
        for(auto x:word2){
            if(u2[x]==1){
                continue;
            }
            u2[x]=1;
            if(st.find(m1[x])!=st.end()){
                st.erase(st.find(m1[x]));
            }
            else{
                return false;
            }
        }
        return true;
    }
};