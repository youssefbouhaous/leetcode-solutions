class Solution {
public:
    string fractionAddition(string exp) {
        vector<pair<int,int>>v;
        int i=0;
        string numerator;
        string denominator;
        while(i<exp.size()){
            numerator.clear();
            denominator.clear();
            numerator.push_back(exp[i]);
            while(exp[i]!='/'){
                i++;
                numerator.push_back(exp[i]);
            }
            i++;
            while(i<exp.size() && exp[i]!='-' && exp[i]!='+'){
                denominator.push_back(exp[i]);
                i++;
            }
            v.push_back({stoi(numerator),stoi(denominator)});
        }
        pair<int,int> a={0,1};
        for(auto x:v){
            a={a.first*x.second+a.second*x.first,a.second*x.second};
            int gcdab=gcd(a.first,a.second);
            a.first=a.first/gcdab;
            a.second=a.second/gcdab;
        }
        cout<<a.first<<"/"<<a.second<<endl;
        a.first=a.first/gcd(a.first,a.second);
        a.second=a.second/gcd(a.first,a.second);
        string ans=to_string(a.first)+"/"+to_string(a.second);
        for(auto x:v){
            cout<<x.first<<"/"<<x.second<<endl;
        }
        return ans;
    }
};