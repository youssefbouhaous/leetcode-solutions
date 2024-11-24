class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        map<string,int>a;
        map<string,int>b;
        string tmp;
        int n=s.size();
        k=n/k;
        for(int i=0;i<n;i++){
            tmp.push_back(s[i]);
            if(((int)tmp.size())%k==0){
                a[tmp]++;
                tmp.clear();
            }
        }
        for(int i=0;i<n;i++){
            tmp.push_back(t[i]);
            if(((int)tmp.size())%k==0){
                b[tmp]++;
                tmp.clear();
            }
        }
        for(auto x:a){
            if(b[x.first]!=x.second) return false;
        }
        for(auto x:b){
            if(a[x.first]!=x.second) return false;
        }
        return true;
    }
};