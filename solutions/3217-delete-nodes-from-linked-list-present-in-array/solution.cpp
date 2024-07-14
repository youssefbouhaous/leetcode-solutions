class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        ListNode* tmp=head;
        ListNode* ans=head;
        if(st.count(tmp->val)){
            while(tmp!=nullptr && st.count(tmp->val)){
                tmp=tmp->next;
            }
        }
        ans=tmp;
        ListNode* prev=tmp;
        while(tmp!=nullptr){
            if(st.count(tmp->val)){
                prev->next=tmp->next;
                tmp=tmp->next;
            }
            else{
                prev=tmp;
                tmp=tmp->next;
            }
        }
        return ans;
    }
};