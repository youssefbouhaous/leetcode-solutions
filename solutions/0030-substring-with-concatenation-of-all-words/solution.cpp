class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int m=words[0].size();
        int r=m*words.size();
        unordered_map<string,int>cnt;
        for(auto x:words){
            cnt[x]++;
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            int c=0;
            unordered_map<string,int>seen;
            int p=i;
            int l=i;
            while(p<n-m+1){
                string w=s.substr(p,m);
                seen[w]++;
                if(cnt.find(w)==cnt.end()){
                    c=0;
                    seen.clear();
                }
                else if(seen[w]>cnt[w]){
                    c++;
                    while(seen[w]>cnt[w]){
                        string tmp=s.substr(l,m);
                        seen[tmp]--;
                        if(cnt.find(tmp)!=cnt.end())c--;
                        l+=m;
                    }
                    //cout<<p<<" l"<<l<<endl;
                    //p=l;
                }
                else{
                    c++;
                }
                if(c==words.size()){
                    ans.push_back(p-m*(words.size()-1));
                }
                p+=m;
            }
        }
        return ans;
    }
};