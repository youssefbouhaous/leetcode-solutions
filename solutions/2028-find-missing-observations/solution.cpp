class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mm, int n) {
        vector<int>ans={};
        double o=6*n;
        double t=0;
        double mean=mm;
        int m=rolls.size();
        for(int i=0;i<m;i++){
            t+=rolls[i];
        }
        if((double)((t+o)/(n+m))<mean) return ans;
        else{
            ans.resize(n,6);
            int i=0;
            while((t+o)/(n+m)>mean && i<n){
                bool f=false;
                for(int j=1;j<6;j++){
                    if((double)((t+o-j)/(n+m))==mean){
                        o-=j;
                        ans[i]-=j;
                        return ans;
                    }
                    else if((double)((t+o-j)/(n+m))<mean){
                        o-=j-1;
                        //cout<<i<<" ans[i]"<<ans[i]<<endl;
                        //cout<<o<<"o"<<endl;
                        ans[i]=ans[i]-j+1;
                        //cout<<i<<" ans[i]"<<ans[i]<<endl;
                        i++;
                        f=true;
                        break;
                    }
                }
                if(f==false){
                    o-=5;
                    ans[i]-=5;
                    i++;
                }
            }
            double l=0;
            for(int i=0;i<n;i++){
                l+=ans[i];
            }
            if((double)((l+t)/(n+m))==mean)
            return ans;
            //cout<<"noo";
            return {};
        }
    }
};