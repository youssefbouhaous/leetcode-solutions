class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int a=asteroids[i];
            if(ans.empty()){
                ans.push_back(a);
            }
            else{
                
                if(a<0 && ans.back()>0){
                    while(a<0 && ans.back()>0){
                        int v=ans.back();
                        ans.pop_back();
                        
                        
                            if(abs(v)<abs(a)){
                                if(ans.empty() || (ans.back()<0 && a<0) || (ans.back()>0 && a>0) || (ans.back()<0 && a>0)){
                                    ans.push_back(a);
                                    break;
                                }
                            }
                            else if(abs(v)>abs(a)){
                                ans.push_back(v);
                                break;
                            }
                            else{
                                break;
                            }
                        
                    }
                }
                else{
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};