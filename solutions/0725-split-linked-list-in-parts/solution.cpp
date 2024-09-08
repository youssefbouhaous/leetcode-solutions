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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* cur=head;
        while(cur!=nullptr){
            n++;
            cur=cur->next;
        }
        cur=head;
        vector<ListNode*>ans;
        vector<int>help(k,n/k);
        n=n-(n/k)*k;
        int i=0;
        while(n){
            help[i]++;
            i++;
            n--;
        }
        reverse(help.begin(),help.end());
        while(!help.empty()){
            if(help.back()==0){
                ans.push_back(nullptr);
                help.pop_back();
            }
            else{
                ans.push_back(cur);
                help.back()--;
                while(help.back()!=0 && cur!=nullptr){
                    cur=cur->next;
                    help.back()--;
                }
                help.pop_back();
                if(cur==nullptr) continue;
                ListNode* nxt=cur->next;
                cur->next=nullptr;
                cur=nxt;
                
            }
        }
        return ans;
    }
};