class Solution {
    int solve1(string& ss, int k){
        int s=0;
        int n=0;
        int e=0;
        int w=0;
        int ans=0;
        for(auto x:ss){
            if(x=='N'){
                n++;
            }
            if(x=='S'){
                if(k>0){
                    n++;
                    k--;
                }
                else
                s++;
                
            }
            if(x=='W'){
                w++;
            }
            if(x=='E'){
                if(k>0){
                    w++;
                    k--;
                }
                else
                e++;
            }
            ans=max(ans,abs(s-n)+abs(w-e));
        }
        return ans;
    }
    int solve2(string& ss, int k){
        int s=0;
        int n=0;
        int e=0;
        int w=0;
        int ans=0;
        for(auto x:ss){
            if(x=='N'){
                n++;
            }
            if(x=='S'){
                if(k>0){
                    n++;
                    k--;
                }
                else
                s++;
                
            }
            if(x=='E'){
                e++;
            }
            if(x=='W'){
                if(k>0){
                    e++;
                    k--;
                }
                else
                w++;
            }
            ans=max(ans,abs(s-n)+abs(w-e));
        }
        return ans;
    }
    int solve3(string& ss, int k){
        int s=0;
        int n=0;
        int e=0;
        int w=0;
        int ans=0;
        for(auto x:ss){
            if(x=='S'){
                s++;
            }
            if(x=='N'){
                if(k>0){
                    s++;
                    k--;
                }
                else
                n++;
                
            }
            if(x=='W'){
                w++;
            }
            if(x=='E'){
                if(k>0){
                    w++;
                    k--;
                }
                else
                e++;
            }
            ans=max(ans,abs(s-n)+abs(w-e));
        }
        return ans;
    }
public:
    int maxDistance(string ss, int k) {
        int s=0;
        int n=0;
        int e=0;
        int w=0;
        int ans1=solve1(ss,k);
        int ans=0;
        int ans2=solve2(ss,k);
        int ans3=solve3(ss,k);
        for(auto x:ss){
            if(x=='S'){
                s++;
            }
            if(x=='N'){
                if(k>0){
                    s++;
                    k--;
                }
                else
                n++;
                
            }
            if(x=='E'){
                e++;
            }
            if(x=='W'){
                if(k>0){
                    e++;
                    k--;
                }
                else
                w++;
            }
            ans=max(ans,abs(s-n)+abs(w-e));
        }
        return max({ans,ans1,ans2,ans3});
    }
};