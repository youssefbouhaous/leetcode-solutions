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
    int best = Integer.MIN_VALUE;
    int f(TreeNode c){
        if(c==null)return 0;
        int d = c.val;
        int a = Math.max(f(c.right),0);
        int b = Math.max(f(c.left),0);
        best = Math.max(best,d+a+b);
        return Math.max(d+a,d+b);
    }
    public int maxPathSum(TreeNode root) {
        f(root);
        return best;
    }
}