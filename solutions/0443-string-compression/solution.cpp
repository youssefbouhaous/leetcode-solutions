class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        string s;
        int o=1;
        int n=chars.size();
        for(int i=1;i<n;i++){
            if(chars[i]!=chars[i-1] && i!=n-1){
                string ot=to_string(o);
                if(o!=1){
                    s.push_back(chars[i-1]);
                    s+=ot;
                    o=1;
                }
                else{
                    s.push_back(chars[i-1]);
                }
            }
            else if(i==n-1){
                if(chars[i]==chars[i-1]){
                    o++;
                }
                else{
                    s.push_back(chars[i-1]);
                    if(o!=1){
                    string ot=to_string(o);
                    s+=ot;
                    }
                    o=1;
                }
                string ot=to_string(o);
                if(o!=1){
                    s.push_back(chars[i]);
                    s+=ot;
                }
                else{
                    s.push_back(chars[i]);
                }
            }
            else{
                o++;
            }
        }
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};