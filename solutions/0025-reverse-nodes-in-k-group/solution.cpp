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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* ans=nullptr;
        ListNode* prevh=nullptr;
        int c=0;
        while(fast!=nullptr){
            c++;
            if(c==k){
                c=0;
                if(ans==nullptr){
                    ans=fast;
                }
                ListNode* nn=fast->next;
                ListNode* next=nullptr;
                ListNode* cur=slow;
                ListNode* prev=nullptr;
                while(cur!=nullptr && cur!=nn){
                    next=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=next;
                }
                if(prevh!=nullptr){
                    prevh->next=prev;
                }
                prevh=slow;
                //cout<<(slow->val)<<endl;
                //cout<<(fast->val)<<endl;
                slow=nn;
                fast=nn;
            }
            else
            fast=fast->next;
        }
        if(c<k){
            prevh->next=slow;
        }
        return ans;
    }
};