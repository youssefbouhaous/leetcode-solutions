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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* tmp=ans;
        int r=0;
        while(l1!=nullptr || l2!=nullptr || r!=0){
            ListNode* t=new ListNode();
            if(l1!=nullptr && l2!=nullptr){
                t->val=(l1->val+l2->val+r)%10;
                r=(l1->val+l2->val+r)/10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1!=nullptr){
                t->val=(l1->val+r)%10;
                r=(l1->val+r)/10;
                l1=l1->next;
            }
            else if(l2!=nullptr){
                t->val=(l2->val+r)%10;
                r=(l2->val+r)/10;
                l2=l2->next;
            }
            else{
                t->val=r;
                r=0;
            }
            ans->next=t;
            ans=t;
            //cout<<ans->val<<" ";
        }
        tmp=tmp->next;
        return tmp;
    }
};