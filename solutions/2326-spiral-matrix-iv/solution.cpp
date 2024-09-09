/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        map<pair<int,int>,bool>vis;
        //cout<<"hh:"<<(head->val)<<endl;
        pair<int,int>d={0,1};
        int o=0;
        int i=0;
        int j=0;
        while(head!=nullptr){
            int ki=i;
            int kj=j;
            if(!vis[{i,j}]){
            ans[i][j]=head->val;
            vis[{i,j}]=true;
            }
            i+=d.first;
            j+=d.second;
            if(i>=m || j>=n || i<0 || j<0 || vis[{i,j}]){
                o++;
                o=o%4;
                if(o==0){
                    d={0,1};
                }
                if(o==1){
                    d={1,0};
                }
                if(o==2){
                    d={0,-1};
                }
                if(o==3){
                    d={-1,0};
                }
                i=ki+d.first;
                j=kj+d.second;
            }
            head=head->next;
        }
        return ans;
    }
};