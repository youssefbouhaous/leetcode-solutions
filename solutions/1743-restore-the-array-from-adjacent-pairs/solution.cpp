class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        map<int,int>d;
        map<int,vector<int>>go;
        map<int,bool>deja;
        int n=arr.size();
        for(int i=0;i<n;i++){
            d[arr[i][0]]++;
            d[arr[i][1]]++;
            go[arr[i][0]].push_back(arr[i][1]);
            go[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int>v(n+1);
        bool f=false;
        for(int i=0;i<n;i++){
            if(!f){
                if(d[arr[i][0]]==1){
                    v[0]=arr[i][0];
                    f=true;
                }
                if(d[arr[i][1]]==1){
                    v[0]=arr[i][1];
                    f=true;
                }
            }
            else{
                if(d[arr[i][0]]==1){
                    v[n]=arr[i][0];
                }
                if(d[arr[i][1]]==1){
                    v[n]=arr[i][1];
                } 
            }
        }
        int b=v[0];
        int j=1;
        deja[b]=true;
        while(b!=v[n]){
            if(!deja[go[b][0]]){
                v[j]=go[b][0];
                deja[go[b][0]]=true;
                b=go[b][0];
            }
            else if(!deja[go[b][1]]){
                v[j]=go[b][1];
                deja[go[b][1]]=true;
                b=go[b][1];
            }
            j++;
        }
        return v;
    }
};