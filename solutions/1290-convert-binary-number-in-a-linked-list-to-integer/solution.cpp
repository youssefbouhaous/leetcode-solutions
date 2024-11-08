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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=nullptr && head->val==0){
            head=head->next;
        }
        int n=0;
        if(head==nullptr) return ans;
        ListNode* a=head;
        while(a!=nullptr){
            n++;
            a=a->next;
        }
        a=head;
        n--;
        while(a!=nullptr){
            ans+=pow(2,n)*(a->val);
            n--;
            a=a->next;
        }
        return ans;
    }
};