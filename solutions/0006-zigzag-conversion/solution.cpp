class Solution {
public:
    string convert(string s, int m) {
        if(m==1){
            return s;
        }
        int i=0;
        int n=s.size();
        string tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(' ');
        }
        vector<string>v(m,tmp);
        int c=0;
        v[0][0]=s[0];
        i++;
        while(i<n){
            for(int j=1;j<m && i<n;j++){
                v[j][c]=s[i];
                i++;
            }
            for(int j=m-2;j>-1 && i<n;j--){
                c++;
                v[j][c]=s[i];
                i++;
            }
        }
        string ans;
        for(auto x:v){
            for(auto y:x){
                if(y!=' '){
                    ans.push_back(y);
                }
            }
            cout<<endl;
        }
        return ans;
    }
};