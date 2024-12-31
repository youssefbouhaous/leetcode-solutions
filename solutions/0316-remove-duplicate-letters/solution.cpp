class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        unordered_map<char,int>mp;
        unordered_map<char,bool>vis;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(vis[s[i]]==true)continue;
            if(ans.empty()){
                ans.push_back(s[i]);
                vis[s[i]]=true;
            }
            else{
                int t=i;
                while(!ans.empty()&& s[i]<ans.back() && mp[ans.back()]>i){
                    vis[ans.back()]=false;
                    ans.pop_back();
                //ans.push_back(s[i]);
                //vis[s[i]]=true;
                t--;
                }
                    //ans.pop_back();
                    ans.push_back(s[i]);
                vis[s[i]]=true;
                
            }
        }
        return ans;
    }
};