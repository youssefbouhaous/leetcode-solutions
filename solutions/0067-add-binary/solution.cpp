class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int r=0;
        int n=a.size();
        int m=b.size();
        int i=0;
        while(i<n || i< m || r!=0){
            if(i<n && i<m){
                int tmp=a[i]-'0'+b[i]-'0'+r;
                c.push_back(tmp%2+'0');
                r=tmp/2;
            }
            else if(i<n){
                int tmp=a[i]-'0'+r;
                c.push_back(tmp%2+'0');
                r=tmp/2;
            }
            else if(i<m){
                int tmp=b[i]-'0'+r;
                c.push_back(tmp%2+'0');
                r=tmp/2;
            }
            else{
                c.push_back(r+'0');
                break;
            }
            i++;
        }
        reverse(c.begin(),c.end());
        return c;
    }
};