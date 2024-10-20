#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    static int block_size;
    int x;
    unordered_map<int,int>freq;
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) const
        {
            return a[1]<b[1];
        }
    };
    void add(vector<int>&log){
        freq[log[0]]++;
    }
    void remove(vector<int>&log){
        freq[log[0]]--;
        if(freq[log[0]]==0){
            freq.erase(log[0]);
        }
    }
    struct Query {
        int l, r, idx;
        bool operator<(Query other) const
        {
            return make_pair( r,l / block_size) <
                make_pair( other.r,other.l / block_size);
        }
    };
    vector<int> mo_s_algorithm(vector<Query>& queries,vector<vector<int>>& logs,int n) {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());
        // TODO: initialize data structure
        int l = 0;
        int r = 0;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries) {
            while(r>0 && r<logs.size() && logs[r][1]>q.r){
                r--;
                remove(logs[r]);
            }
            while(r>=0 && r<logs.size() && logs[r][1]<=q.r){
                add(logs[r]);
                r++;
            }
            while(l>0 && l<logs.size() && logs[l][1]>=q.l){
                l--;
                add(logs[l]);
            }
            while(l>=0 && l<logs.size() && logs[l][1]<q.l){
                remove(logs[l]);
                l++;
            }
            answers[q.idx]=(n-(int)freq.size());
            if(freq.find(INT_MIN)!=freq.end()){
                answers[q.idx]++;
            }
            if(freq.find(INT_MAX)!=freq.end()){
                answers[q.idx]++;
            }
        }
        return answers;
    }
    public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int xx, vector<int>& queries) {
        int x=xx;
        block_size=(int)((int)logs.size()+.0)+1;
        logs.push_back({INT_MIN,INT_MIN});
        logs.push_back({INT_MAX,INT_MAX});
        sort(logs.begin(),logs.end(),cmp());
        vector<Query> qs;
        for(int i=0;i<queries.size();i++){
            int q=queries[i];
            Query tmp;
            tmp.l = q - x;
            tmp.r = q;
            tmp.idx = i;
            qs.push_back(tmp);
        }
        return mo_s_algorithm(qs,logs,n);
    }
};
int Solution::block_size = 0;