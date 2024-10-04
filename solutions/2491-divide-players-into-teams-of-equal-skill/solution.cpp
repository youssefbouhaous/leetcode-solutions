class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        vector<pair<int,int>>teams;
        int n=skill.size();
        for(int i=0;i<skill.size()/2;i++){
            teams.push_back({skill[i],skill[n-i-1]});
            if(teams.size()>=2 && teams[i].first+teams[i].second!=teams[i-1].first+teams[i-1].second){
                return -1;
            }
        }
        long long int ans=0;
        for(auto x:teams){
            ans+=((long long int)(x.first))*((long long int )(x.second));
        }
        return ans;
    }
};