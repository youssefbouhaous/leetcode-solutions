class Solution {
    unordered_map<string,bool>mp;
    int ans=0;
    int f(string &s,int start){
        if(start==s.size()) return 0;
        int count=0;
        for(int end=start+1;end<=s.size();end++){
            string sub=s.substr(start,end-start);
            if(mp.find(sub)==mp.end()){
                mp[sub]=true;
                count=max(count,1+f(s,end));
                mp.erase(sub);
            }
        }
        return count;
    }
public:
    int maxUniqueSplit(string s) {
        string o="";
        return f(s,0);
    }
};