class Solution {
public:
    int maximumSwap(int num) {
        set<int>st;
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                swap(s[i],s[j]);
                st.insert(stoi(s));
                swap(s[i],s[j]);
            }
        }
        return (*(--st.end()));
    }
};