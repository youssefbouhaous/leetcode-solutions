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
    ListNode* deleteDuplicates(ListNode* head) {
       bool f=false;
       if(head==nullptr){
        return nullptr;
       }
       if(head->next==nullptr){
        return head;
       }
       ListNode* ans=head;
       ListNode* hh=head;
       ListNode* ansf=new ListNode(head->val);
       ListNode* ansff=ansf;
       int l=-101;
       while(head!=nullptr){
        ListNode* n=new ListNode();
        
            if(head->next==nullptr && head->val!=l){
                n->val=head->val;
                ansf->next=n;
                ansf=n;
            }
            else if(head->val==l){
                
            }
            else if(head->next->val!=head->val){
                n->val=head->val;
                ansf->next=n;
                ansf=n;
                l=head->val;
                f=false;
            }
            else if(head->next->val==head->val){
                l=head->val;
                f=true;
            }
            head=head->next;
       } 
       return ansff->next;
    }
};