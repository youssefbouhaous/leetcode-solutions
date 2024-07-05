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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        ListNode* fast=head;
        ListNode* slow=head;
        vector<int>st;
        int c=0;
        while(fast->next!=nullptr){
            fast=fast->next;
            c++;
            if(fast->next!=nullptr){
                if( (fast->val) < (fast->next->val) && (fast->val) < slow->val ){
                    st.push_back(c);
                }
                if( (fast->val) > (fast->next->val) && (fast->val) > slow->val ){
                    st.push_back(c);
                }
            }
            slow=slow->next;
        }
        if(st.size()<2){
            return ans;
        }
        ans[1]=st.back()-st[0];
        ans[0]=st.back()-st[0];
        for(int i=0;i<st.size()-1;i++){
            ans[0]=min(ans[0],st[i+1]-st[i]);
        }
        return ans;
    }
};