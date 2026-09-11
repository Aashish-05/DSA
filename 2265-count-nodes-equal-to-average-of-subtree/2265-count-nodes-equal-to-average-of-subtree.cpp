/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findSum(TreeNode* root,int &cnt){
        if(root==NULL) return 0;
        cnt++;
        int ls = findSum(root->left,cnt);
        int rs = findSum(root->right,cnt);
        return ls+rs+root->val;
    }
    int solve(TreeNode* root) {
        int maxi = 0;
        if (root == NULL) return 0;
        int cnt = 0;
        int sum = findSum(root,cnt);
        if(sum/cnt==root->val) maxi++;
        maxi+=solve(root->left);
        maxi+=solve(root->right);
        return maxi;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        return solve(root);
    }
};