class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char>d;
        map<char,string>d2;
        string tmp;
        int countW=0;
        int i=0;
        for(auto x:s){
            if(x==' '){
                d[tmp]=pattern[i];
                d2[pattern[i]]=tmp;
                i++;
                tmp.clear();
                countW++;
            }
            else
            tmp.push_back(x);
        }
        countW++;
        if(countW!=pattern.size()){
            return false;
        }
        d[tmp]=pattern[i];
        d2[pattern[i]]=tmp;
        tmp.clear();
        i=0;
        for(auto x:s){
            if(x==' '){
                if(
                d[tmp]!=pattern[i] || 
                d2[pattern[i]]!=tmp){ 
                    return false;}
                i++;
                tmp.clear();
            }
            else
            tmp.push_back(x);
        }
        if(d[tmp]!=pattern[i] || d2[pattern[i]]!=tmp){ 
            //cout<<"here";
            return false;
        }
        return true;
    }
};