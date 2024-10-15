class Solution {
public:
    long long minimumSteps(string s) {
        deque<int>o;
        deque<int>z;
        int no=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){no++;}
        }
       for(int i=0;i<n;i++){
        //cout<<s[i]<<" "<<i<<endl;
            if(s[i]=='1' && i<n-no){o.push_back(i);}
            if(s[i]=='0' && i>=n-no){z.push_back(i);}
       }
       long long ans=0;
        while(!o.empty() && !z.empty()){
            ans+=-(long long)o.back()+(long long)z.front();
            //cout<<(o.back())<<" "<<(z.front())<<endl;
            o.pop_back();
            z.pop_front();
        }
        return ans;
    }
};