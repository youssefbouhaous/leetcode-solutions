class Solution {
public:
    unordered_map<int, vector<int>> tree;
    unordered_map<int, bool> vv;

    void f(TreeNode* n, TreeNode* p) {
        if (n == nullptr) return;
        int v = n->val;
        tree[v] = {-1, -1, -1}; // Initialize with no neighbors
        vv[v] = true;
        if (n != p) {
            tree[v][0] = p->val; // Parent node
        }
        if (n->left != nullptr && !vv[n->left->val]) {
            tree[v][1] = n->left->val; // Left child
            vv[n->left->val] = true;
            f(n->left, n);
        }
        if (n->right != nullptr && !vv[n->right->val]) {
            tree[v][2] = n->right->val; // Right child
            vv[n->right->val] = true;
            f(n->right, n);
        }
    }

    string getDirections(TreeNode* root, int s, int e) {
        f(root, root);

        queue<int> q;
        unordered_map<int, bool> vis;
        unordered_map<int, pair<int, char>> path;
        q.push(s);
        vis[s] = true;

        while (!q.empty()) {
            int nxt = q.front();
            q.pop();
            vector<int> neighbors = tree[nxt];
            
            if (neighbors[0] != -1 && !vis[neighbors[0]]) {
                path[neighbors[0]] = {nxt, 'U'};
                if (neighbors[0] == e) {
                    break;
                }
                vis[neighbors[0]] = true;
                q.push(neighbors[0]);
            }

            if (neighbors[1] != -1 && !vis[neighbors[1]]) {
                path[neighbors[1]] = {nxt, 'L'};
                if (neighbors[1] == e) {
                    break;
                }
                vis[neighbors[1]] = true;
                q.push(neighbors[1]);
            }

            if (neighbors[2] != -1 && !vis[neighbors[2]]) {
                path[neighbors[2]] = {nxt, 'R'};
                if (neighbors[2] == e) {
                    break;
                }
                vis[neighbors[2]] = true;
                q.push(neighbors[2]);
            }
        }

        string ans = "";
        while (e != s) {
            ans.push_back(path[e].second);
            e = path[e].first;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
