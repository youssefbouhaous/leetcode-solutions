#define vi vector<int>
#define rep(i,a,n) for(int i=a;i<n;i++)
class Solution {
public:
    long long countSubstrings(string s) {
        const int n = s.length();
        long long ret = 0;
        unordered_map<int,int>suf;
        for(auto x:s){
            suf[x-'a']++;
        }
        rep(i,0,n){
            int d = s[i]-'0';
            if(d==1 || d==2 || d==5) ret += (i+1);
        }
        {
            vi pre(n+1);
            rep(i,0,n) pre[i+1] = (pre[i]+(s[i]-'0'))%3;
            vi f(3);
            f[pre[0]]++;
            rep(i,0,n){
                if(s[i]=='3') ret += f[pre[i+1]];
                f[pre[i+1]]++;
            }
        }
        {
            vi pre(n+1);
            rep(i,0,n) pre[i+1] = (pre[i]+(s[i]-'0'))%9;
            vi f(9);
            f[pre[0]]++;
            rep(i,0,n){
                if(s[i]=='9') ret += f[pre[i+1]];
                f[pre[i+1]]++;
            }
        }
        {
            vi pre(n+1);
            rep(i,0,n) pre[i+1] = (pre[i]*10+(s[i]-'0'))%6;
            vi f(6);
            f[pre[0]]++;
            rep(i,0,n){
                if(s[i]=='6'){
                    rep(r,0,6) if((r*4)%6==pre[i+1]) ret += f[r];
                }
                f[pre[i+1]]++;
            }
        }
        {
            const int d=7,p=6;
            vi pre(n+1);
            rep(i,0,n) pre[i+1] = (pre[i]*10+(s[i]-'0'))%d;
            vi B(p);
            B[0]=1;
            rep(i,1,p) B[i]=(B[i-1]*10)%d;
            vector<vi> f(p,vi(d));
            f[0][pre[0]]++;
            rep(i,0,n){
                int t=i+1;
                if(s[i]=='7'){
                    int tmod=t%p;
                    rep(x,0,p){
                        int exp=(tmod-x+p)%p;
                        rep(r,0,d) if((r*B[exp])%d==pre[t]) ret+=f[x][r];
                    }
                }
                int b=t%p;
                f[b][pre[t]]++;
            }
        }
        {
            const int d=4;
            vi pre(n+1);
            rep(i,0,n) pre[i+1]=(pre[i]*10+(s[i]-'0'))%d;
            rep(i,0,n){
                if(s[i]=='4'){
                    int t=i+1;
                    ret++;
                    if(t>=2 && pre[t]==0) ret+=(t-1);
                }
            }
        }
        {
            const int d=8;
            vi pre(n+1);
            rep(i,0,n) pre[i+1]=(pre[i]*10+(s[i]-'0'))%d;
            rep(i,0,n){
                if(s[i]=='8'){
                    int t=i+1;
                    ret++;
                    if(t>=2){
                        int tw=((s[t-2]-'0')*10+(s[t-1]-'0'))%d;
                        if(tw==0) ret++;
                    }
                    if(t>=3 && pre[t]==0) ret+=(t-2);
                }
            }
        }
        return ret;
    }
};