class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        int c=1;
        int i=0;
        vector<char>s;
        while(i<chars.size()-1){
            if(chars[i]!=chars[i+1]){
                s.push_back(chars[i]);
                if(c!=1){
                for(auto x: to_string(c)){
                    s.push_back(x);
                }
                }
                ans+=c+to_string(c).size();
                c=1;
            }
            else{
                c++;
            }
            i++;
        }
        s.push_back(chars.back());
        if(c!=1){
        for(auto x : to_string(c)){
            s.push_back(x);
        }
        }
        ans=s.size();
        chars=s;
        /*for(auto x:chars){
            cout<<x<<"::";
        }*/
        return ans;
    }
};