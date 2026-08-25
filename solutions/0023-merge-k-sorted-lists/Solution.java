/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode merge(ListNode a,ListNode b){
        ListNode tmp=new ListNode();
        ListNode ans=tmp;
        while(a!=null && b!=null){
            if(a.val<b.val){
                tmp.next=a;
                a=a.next;
            }else{
                tmp.next=b;
                b=b.next;
            }
            tmp=tmp.next;
        }
        if(a==null){
            tmp.next=b;
        }else{
            tmp.next=a;
        }
        return ans.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int i=0;
        int j=1;
        int n=lists.length;
        if(n<1)return null;
        if(n<2)return lists[0];
        while(j<n){
            lists[j]=merge(lists[i],lists[j]);
            i++;j++;
        }
        return lists[n-1];
    }
}