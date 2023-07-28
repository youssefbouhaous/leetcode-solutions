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
    int pairSum(ListNode* head) {
        ListNode* rev=new ListNode;
        rev->val=head->val;
        rev->next=nullptr;
        ListNode* p=head->next;
        while(p!=nullptr){
            ListNode* tmp=new ListNode;
            tmp->val=p->val;
            tmp->next=rev;
            rev=tmp;
            p=p->next;
        }
        int ans=0;
        while(head!=nullptr){
            ans=max(head->val+rev->val,ans);
            head=head->next;
            rev=rev->next;
        }
        return ans;
    }
};