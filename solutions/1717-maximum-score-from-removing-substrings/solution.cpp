class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a=0;
        int b=0;
        bool f=true;
        int n=s.size();
        string tmp;
        tmp.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(!tmp.empty() && s[i]=='b' && tmp.back()=='a'){
                a+=x;
                tmp.pop_back();
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        string tmp2;
        if(!tmp.empty()){
            tmp2.push_back(tmp[0]);
            for(int i=1;i<tmp.size();i++){
            if(!tmp2.empty() && tmp[i]=='a' && tmp2.back()=='b'){
                a+=y;
                tmp2.pop_back();
            }
            else{
                tmp2.push_back(tmp[i]);
            }
        }
        }
        tmp.clear();
        tmp.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(!tmp.empty() && s[i]=='a' && tmp.back()=='b'){
                b+=y;
                tmp.pop_back();
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        tmp2.clear();
        if(!tmp.empty()){
            tmp2.push_back(tmp[0]);
            for(int i=1;i<tmp.size();i++){
            if(!tmp2.empty() && tmp[i]=='b' && tmp2.back()=='a'){
                b+=x;
                tmp2.pop_back();
            }
            else{
                tmp2.push_back(tmp[i]);
            }
        }
        }
        
        return max(a,b);
    }
};