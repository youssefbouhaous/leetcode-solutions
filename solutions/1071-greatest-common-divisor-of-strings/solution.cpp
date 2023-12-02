class Solution {
public:



    int gcd(int n,int m){
        if(m==0){
            return n;
        }
        return gcd(m,n%m);
    }
    string gcdOfStrings(string a, string b) {
        if(a.size()*b.size()==0){
            return "";
        }
        if(a[0]!=b[0]){
            return "";
        }
        else{
            int o=gcd(a.size(),b.size());
            string re = a.substr(0,o);
            for(int i=0;i<a.size();i+=o){
                if(a.substr(i,o)!=re){
                    return "";
                }
            }
            for(int i=0;i<b.size();i+=o){
                if(b.substr(i,o)!=re){
                    return "";
                }
            }
            return re;
        }
    }
};