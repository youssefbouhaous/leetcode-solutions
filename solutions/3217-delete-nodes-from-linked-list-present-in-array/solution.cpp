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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       set<int>st;
       for(auto x:nums){
        st.insert(x);
       } 
       while(head!=nullptr){
            if(st.count(head->val)){
                head=head->next;
            }
            else{
                break;
            }
       }
       if(head==nullptr) return head;
       ListNode* prev=head;
       ListNode* cur=head->next;
       while(cur!=nullptr){
            if(st.count(cur->val)){
                prev->next=cur->next;
                cur=prev->next;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
       }
       return head;
    }
};