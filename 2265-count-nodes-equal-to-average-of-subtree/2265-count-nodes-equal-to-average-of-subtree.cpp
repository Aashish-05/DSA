/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) return 0;

        int ans = 0;

        function<pair<int,int>(TreeNode*)> solve = [&](TreeNode* node) {
            if (node == NULL) return make_pair(0, 0);

            auto l = solve(node->left);
            auto r = solve(node->right);

            int sum = node->val + l.first + r.first;
            int cnt = 1 + l.second + r.second;

            if (sum / cnt == node->val)
                ans++;

            return make_pair(sum, cnt);
        };

        solve(root);
        return ans;
    }
};