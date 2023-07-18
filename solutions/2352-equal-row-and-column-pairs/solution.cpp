class Solution {
public:
    int hash_f(vector<int> v){
        long long ans=0;
        for(int i=1;i<=v.size();i++){
            ans=(ans%(1000000007LL)+(long long)(v[i-1]*pow(31,i))%(1000000007LL))%(1000000007LL);
        }
        return (int)(ans%(1000000007LL));
    }
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>v1;
        vector<int>v2;
        int n=grid.size();
        for(int i=0;i<n;i++){
            v1[grid[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(grid[j][i]);
            }
            /*for(auto x: tmp){
                cout<<x<<"::";
            }
            cout<<endl;*/
            if(v1[tmp]>0){
                ans+=v1[tmp];
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v1[i]==v2[j]){
                    ans++;
                }
            }
        }*/
        return ans;
    }
};