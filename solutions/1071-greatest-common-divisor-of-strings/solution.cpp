class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans;
        vector<string>d2;
        int n=str2.size();
        int m=str1.size();
        for(int i=0;i<n;i++){
            int a=n/(i+1);
            string tmp;
            string x=str2.substr(0,i+1);
            //cout<<"::"<<x<<endl;
            while(tmp.size()<n){
                tmp=tmp+x;
            }
            //cout<<tmp<<endl;
            if(tmp==str2){
                d2.push_back(x);
            }
        }
        d2.push_back(str2);
        for(auto x:d2){
            int a=0;
            string tmp;
            while(tmp.size()<m){
                tmp=tmp+x;
            }
            //cout<<"x : "<<x<<endl;
            //cout<<tmp<<endl;
            if(tmp==str1 && x.size()>ans.size()){
                ans=x;
            }
        }
        if(str1==str2){
            return str1;
        }
        else{
            return ans;
        }
    }
};