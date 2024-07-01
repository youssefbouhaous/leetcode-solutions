class Solution {
public:
    int myAtoi(string s) {
        char r=s[0];
        int i=0;
        int n=s.size();
        int nmax=2147483647;
        
        while(r==' ' || r=='0' && i<n){
            if(r=='0' && i+1<n && !(s[i+1]>='0' && s[i+1]<='9')){
                break;
            }
            i++;
            r=s[i];
        }
        int m=n;
        if(r=='-' || r=='+'){
            i++;
        }
        while( i<n && (s[i]=='0')){
             if(i+1<n && !(s[i+1]>='0' && s[i+1]<='9')){
                break;
            }
            i++;
        }
        cout<<i<<endl;
        for(int j=i;j<n;j++){
            if(!(s[j]>='0' && s[j]<='9')){
                m=j;
                break;
            }
        }
        //cout<<m<<endl;
        int c=0;
        long long int ans=0;
        if(r!='-' && m-i+1>=12){
            return 2147483647;
        }
        else if(m-i+1>=12){
            return -2147483648;
        }
        for(int j=m-1;j>=i;j--){
            if(r=='-')
            ans-=((s[j]-'0')*pow(10,c));
            else
            ans+=((s[j]-'0')*pow(10,c));
            c++;
            if(r!='-' && ans>=(long long int)nmax){
                return nmax;
            }
            else if(r=='-' && ans<=(-2147483648)){
                return -2147483648;
            }
        }
        cout<<"ans"<<ans;
        return ans;
    }
};