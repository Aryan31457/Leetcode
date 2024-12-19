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
    TreeNode* solve(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend, 
                    unordered_map<int, int>& mappi) {
        if (poststart > postend || instart > inend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mappi[root->val];
        int left = inroot - instart;

        root->left = solve(postorder, poststart, poststart + left - 1, inorder, instart, inroot - 1, mappi);
        root->right = solve(postorder, poststart + left, postend - 1, inorder, inroot + 1, inend, mappi);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mappi;
        for (int i = 0; i < inorder.size(); i++) {
            mappi[inorder[i]] = i;
        }
        return solve(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mappi);
    }
};
