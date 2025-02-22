class Solution {
public:
    int splitNum(int num) {
        string p=to_string(num);
        int n=p.size();
        string aa;
        int ans=num;
        sort(p.begin(),p.end());
        string a;
        string b;
        for(int i=0;i<n;i+=2){
            a.push_back(p[i]);
        }
        for(int i=1;i<n;i+=2){
            b.push_back(p[i]);
        }
        return stoi(a)+stoi(b);
    }
};