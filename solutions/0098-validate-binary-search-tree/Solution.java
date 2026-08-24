/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean f(TreeNode c){
        if(c==null || (c.left==null && c.right==null))return true;
        long mx = max(c.left);
        long mn = min(c.right);
        long d = c.val;
        if(d<=mx || d>=mn)return false;
        return f(c.left)&f(c.right);
    }
    long max(TreeNode c){
        if(c==null)return Long.MIN_VALUE;
        return Collections.max(List.of(max(c.right),max(c.left),(long)c.val));
    }
    long min(TreeNode c){
        if(c==null)return Long.MAX_VALUE;
        return Collections.min(List.of(min(c.right),min(c.left),(long)c.val));
    }
    public boolean isValidBST(TreeNode root) {
        return f(root);
    }
}