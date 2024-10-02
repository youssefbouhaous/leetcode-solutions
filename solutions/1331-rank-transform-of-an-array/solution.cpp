class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        vector<int>v=arr;
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(mp[v[i]]==0){
                cnt++;
                mp[v[i]]=cnt;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};