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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* p=head;
        int n=0;
        while(p!=nullptr){
            //cout<<p->val;
            p=p->next;
            n++;
        }
        ListNode* pp=head;
        int tt=1;
        while(pp!=nullptr){
            if(tt==n/2){
                ListNode* ppp=pp->next;
                if(ppp!=nullptr)
                pp->next=ppp->next;
                else{
                    pp->next=ppp;
                }
                break;
            }
            pp=pp->next;
            tt++;
        }
        return head;
    }
};