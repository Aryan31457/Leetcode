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
    void solve(TreeNode* leftchild,TreeNode* rightchild,int cnt){
        if(leftchild==NULL|| rightchild==NULL)return;

        if(cnt%2==1){
            int temp=rightchild->val;
            rightchild->val=leftchild->val;
            leftchild->val=temp;
        }

        solve(leftchild->left,rightchild->right,cnt+1);
        solve(leftchild->right,rightchild->left,cnt+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)return NULL;

        solve(root->left,root->right,1);
        
        return root;
        
    }
};