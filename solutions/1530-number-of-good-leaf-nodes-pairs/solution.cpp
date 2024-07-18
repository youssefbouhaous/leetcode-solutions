class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        vector<int> helper = dfs(root, distance, result);
        return result;
    }

    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        
        // Leaf node
        if (!node->left && !node->right) return {1};

        vector<int> leftDistances, rightDistances;
        if (node->left) leftDistances = dfs(node->left, distance, result);
        if (node->right) rightDistances = dfs(node->right, distance, result);

        // Count the pairs
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) result++;
            }
        }
        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 <= distance) currentDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 <= distance) currentDistances.push_back(r + 1);
        }
        return currentDistances;
    }
};