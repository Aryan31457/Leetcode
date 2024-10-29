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
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }

    void sumAtLevels(TreeNode* root, int level, vector<int>& sumPerLevel) {
        if (root == nullptr) return;
        sumPerLevel[level] += root->val;
        sumAtLevels(root->left, level + 1, sumPerLevel);
        sumAtLevels(root->right, level + 1, sumPerLevel);
    }

   void replace(TreeNode* root, int sib, vector<int>& mp, int depth) {
        if (!root) return;

        int leftSibling = 0, rightSibling = 0;
        if (root->left) leftSibling = root->left->val;
        if (root->right) rightSibling = root->right->val;

        int ans = mp[depth] - root->val - sib;

        root->val = ans;

        replace(root->right, leftSibling, mp, depth + 1);
        replace(root->left, rightSibling, mp, depth + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return root;

        int height = depth(root);
        vector<int> sumPerLevel(height, 0);
        sumAtLevels(root, 0, sumPerLevel);
        replace(root, 0, sumPerLevel,0);

        return root;
    }
};