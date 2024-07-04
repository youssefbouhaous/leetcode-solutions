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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* anss=ans;
        ListNode* tmp=ans->next;
        int s=0;
        while(head!=nullptr){
            s+=head->val;
            if(head->val==0){
                ans->val=s;
                ListNode* n= new ListNode();
                if(head->next!=nullptr){
                ans->next=n;
                ans=n;}
                s=0;
            }
            head=head->next;
        }
        return anss->next;
    }
};