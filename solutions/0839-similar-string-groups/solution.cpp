class Solution {
public:


    unordered_map<string,string>parent;
    unordered_map<string,int>rank;
    void make(string v){
        parent[v]=v;
        rank[v]=0;
    }
    string find(string v){
        if(parent[v]=="") return parent[v]=v;
        if(parent[v]== v)return v;
        return parent[v]=find(parent[v]);
    }

    void unions(string a,string b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b]=a;
            if(rank[a]==rank[b]){
                rank[a]++;
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        set<string>st;
        for(auto x:strs){
            make(x);
            st.insert(x);
        }
        int n=strs.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>d;
                for(int l=0;l<strs[0].size();l++){
                    if(strs[i][l]!=strs[j][l]){
                        d.push_back(l);
                    }
                    if(d.size()>2){
                        break;
                    }
                }
                if(d.size()==2 && strs[i][d[0]]==strs[j][d[1]] && strs[i][d[1]]==strs[j][d[0]]){
                    unions(strs[i],strs[j]);
                }
            }
        }
        map<string,bool>deja;
        int ans=0;
        for(auto x:strs){
            if(!deja[find(x)]){
                //cout<<find(x)<<" "<<x<<endl;
                ans++;
                deja[find(x)]=true;
            }
        }
        return ans;
    }
};