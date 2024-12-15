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
//Using 1 stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s1;
        s1.push(root);
        TreeNode* s2=root;
        while(!s1.empty()){ 
            s2=s1.top();
            ans.push_back(s2->val);
            s1.pop();
            TreeNode* node=s2;
            if(node!=NULL){
            if(node->left)s1.push(node->left);
            if(node->right)s1.push(node->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};