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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* ans=new ListNode();
        ListNode* tmp=ans;
        while(a!=nullptr || b!=nullptr){
            ListNode* t=new ListNode();
            if(a!=nullptr && b!=nullptr){
                if(a->val<b->val){
                    t->val=a->val;
                    a=a->next;
                }
                else{
                    t->val=b->val;
                    b=b->next;
                }
            }
            else if(a!=nullptr){
                t->val=a->val;
                a=a->next;
            }
            else{
                //cout<<"o";
                //cout<<b->val;
                t->val=b->val;
                b=b->next;
            }
            tmp->next=t;
            tmp=t;
        }
        ans=ans->next;
        return ans;
    }
};