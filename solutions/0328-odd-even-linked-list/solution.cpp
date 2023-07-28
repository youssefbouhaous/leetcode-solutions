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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* even=new ListNode;
        ListNode* evend=even;
        ListNode* odd=new ListNode;
        ListNode* oddd=odd;
        even->val=head->val;
        even->next=nullptr;
        if(head->next==nullptr){
            return head;
        }
        odd->val=(head->next)->val;
        odd->next=nullptr;
        ListNode* p=(head->next)->next;
        int n=1;
        while(p!=nullptr){
            n++;
            //cout<<p->val;
            if(n%2==0){
                even->next=p;
                p=p->next;
                even=even->next;
                even->next=nullptr;
            }
            else{
                odd->next=p;
                p=p->next;
                odd=odd->next;
                odd->next=nullptr;
            }
        }
        even->next=oddd;
        return evend;
    }
};